FROM node:16.3-alpine3.12 as build

ENV TERM=dumb
ENV LD_LIBRARY_PATH=/usr/local/lib:/usr/lib:/lib

RUN set NODE_OPTIONS=--max-old-space-size=30720

RUN mkdir /esy
WORKDIR /esy

ENV NPM_CONFIG_PREFIX=/esy
RUN npm install -g esy@0.6.12

# Alpine image where
FROM node:16.3-alpine3.12 as esy

ENV TERM=dumb
ENV LD_LIBRARY_PATH=/usr/local/lib:/usr/lib:/lib

COPY --from=build /esy /esy

RUN apk add --no-cache ca-certificates wget bash curl perl-utils git patch gcc g++ musl-dev make m4 coreutils tar xz linux-headers

RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk
RUN apk add --no-cache glibc-2.28-r0.apk

ENV PATH=/esy/bin:$PATH

WORKDIR /app

# Install npm dependencies
COPY package*.json ./
RUN npm ci --only=production

# Install esy dependencies
ADD esy.json esy.json
ADD esy.lock/ esy.lock/
RUN esy --version
RUN esy solve
RUN esy fetch
RUN esy build-dependencies

# Copy the project (move folder by folder instead of COPY . . to not override _esy folder)
COPY client/ client/
COPY shared/ shared/
COPY server/ server/
COPY vendor/ vendor/
COPY dune dune
COPY dune-project dune-project
COPY webpack.config.js webpack.config.js

# Build client
RUN esy build
# Bundle client
RUN node_modules/.bin/webpack
# Build server
RUN esy dune build --profile=prod @@default

FROM alpine:3.12 as run

RUN apk update && apk add --update libev gmp git

RUN chmod -R 755 /var

# Copy server binary
COPY --from=esy /app/_build/default/server/server.exe /bin/server.exe
# Copy client artifacts
COPY --from=esy /app/static /static

ENV SERVER_INTERFACE "0.0.0.0"

CMD ["/bin/server.exe"]

FROM debian:stable-slim as build

RUN apt-get update
RUN apt-get install -y curl git m4 npm nodejs unzip

WORKDIR /build

# Install npm dependencies
COPY package*.json ./
RUN npm ci --only=production

# Install esy dependencies
ADD esy.* .
RUN node_modules/.bin/esy solve
RUN node_modules/.bin/esy fetch
RUN node_modules/.bin/esy build-dependencies

# Copy the project (move folder by folder instead of COPY . . to not override _esy folder)
COPY client/ client/
COPY shared/ shared/
COPY server/ server/
COPY reason-react/ reason-react/
COPY dune dune
COPY dune-project dune-project
COPY webpack.config.js webpack.config.js

# Build client
RUN node_modules/.bin/esy build
# Bundle client
RUN node_modules/.bin/webpack
# Build server
RUN node_modules/.bin/esy dune build --profile=prod @@default

FROM alpine:3.12 as run

RUN apk update && apk add --update libev gmp git

RUN chmod -R 755 /var

# Copy server binary
COPY --from=build /build/_build/default/server/server.exe /bin/server.exe
# Copy client artifacts
COPY --from=build /build/static /static

CMD ["/bin/server.exe"]

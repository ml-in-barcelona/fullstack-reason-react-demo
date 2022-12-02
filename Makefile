.DEFAULT_GOAL := help

ESY = esy
DUNE = esy dune
MEL = esy mel
WEBPACK = npx webpack --progress
current_hash = $(shell git rev-parse HEAD | cut -c1-7)
name = fullstack-reason-react-demo

.PHONY: install
install: ## Install dependencies from @opam, github and NPM repository
	$(ESY) install
	npm install

.PHONY: client-bundle
client-bundle: ## Bundle the JS code
	$(WEBPACK)

.PHONY: client-bundle-watch
client-bundle-watch: ## Watch and bundle the JS code
	$(WEBPACK) --watch

.PHONY: client-bundle
client-bundle-prod: ## Bundle the JS code for production
	$(WEBPACK) --env production

.PHONY: client-build
client-build: ## Build Reason code
	$(ESY) build

.PHONY: client-build-watch
client-build-watch: ## Watch reason code
	$(DUNE) build -w @client

.PHONY: server-build
server-build: ## Build the project, including non installable libraries and executables
	$(DUNE) build @@default

.PHONY: server-build-prod
server-build-prod: ## Build for production (--profile=prod)
	$(DUNE) build --profile=prod @@default

.PHONY: server-start
server-start: ## Start the server
	$(DUNE) exec --root . server/server.exe

.PHONY: server-dev
server-dev: ## Build in watch mode
	$(DUNE) build -w @@default

.PHONY: dev
dev: ## Start the server in dev mode
	@watchexec \
		-w client -w server -w shared \
		--exts re,rei,ml,mli -r -c \
		"$(MAKE) client-build; $(MAKE) server-build; $(MAKE) client-bundle; $(MAKE) server-start"

.PHONY: clean
clean: ## Clean artifacts
	$(DUNE) clean

.PHONY: format
format: ## Format the codebase with ocamlformat/refmt
	$(DUNE) build @fmt --auto-promote

.PHONY: format-check
format-check: ## Checks if format is correct
	$(DUNE) build @fmt

.PHONY: help
help: ## Print this help message
	@echo "";
	@echo "List of available make commands:";
	@echo "";
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}';
	@echo "";

.PHONY: commit
commit:
	@echo "Copied hash in copy: $(current_hash)";
	@echo $(current_hash) | pbcopy;

.PHONY: docker-build
docker-build: ## docker build
	docker build . --tag "$(name):$(current_hash)" --platform linux/amd64 --progress=plain

.PHONY: docker-run
docker-run: ## docker run
	docker run -d --platform linux/amd64 \
	$(name):$(current_hash)

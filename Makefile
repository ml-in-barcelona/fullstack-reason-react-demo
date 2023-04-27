.DEFAULT_GOAL := help

name = fullstack-reason-react-demo
current_hash = $(shell git rev-parse HEAD | cut -c1-7)

ESY = esy
DUNE = esy dune
WEBPACK = npx webpack --progress

.PHONY: install
install: ## Install dependencies from esy.json and package.json
	@$(ESY) install
	@npm install

.PHONY: webpack
webpack: ## Bundle the JS code
	@$(WEBPACK) --env development

.PHONY: webpack-prod
webpack-prod: ## Bundle the JS code for production
	@$(WEBPACK) --env production

.PHONY: webpack-watch
webpack-watch: ## Watch and bundle the JS code
	@$(WEBPACK) --watch --env development

.PHONY: build-client
build-client: ## Build Reason code
	@$(DUNE) build @client

.PHONY: build-client-watch
build-client-watch: ## Watch reason code
	@$(DUNE) build -w @client

.PHONY: build-server-prod
build-server-prod: ## Build for production (--profile=prod)
	@$(DUNE) build --profile=prod @server

.PHONY: build-server
build-server: ## Build the project, including non installable libraries and executables
	@$(DUNE) build @server

.PHONY: start-server
start-server: ## Start the server
	@$(DUNE) exec server/server.exe

.PHONY: run
run: ## Start the server in dev mode
	@watchexec --no-ignore -w .processes/last_built_at.txt -r -c \
	"clear; _build/default/server/server.exe"

.PHONY: watch
watch: ## Build in watch mode
	@$(DUNE) build -w @client @server

.PHONY: clean
clean: ## Clean artifacts
	@$(DUNE) clean
	@rm -rf static/

.PHONY: format
format: ## Format the codebase with ocamlformat/refmt
	@$(DUNE) build @fmt --auto-promote

.PHONY: format-check
format-check: ## Checks if format is correct
	@$(DUNE) build @fmt

.PHONY: help
help: ## Print this help message
	@echo "";
	@echo "List of available make commands:";
	@echo "";
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}';
	@echo "";

.PHONY: docker-build
docker-build: ## docker build
	@docker build . --tag "$(name):$(current_hash)" --platform linux/amd64 --progress=plain

.PHONY: docker-run
docker-run: ## docker run
	@docker run -d --platform linux/amd64 \
	@$(name):$(current_hash)

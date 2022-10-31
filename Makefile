project_name = fullstack-react

DUNE = esy dune
MEL = esy mel
# current_hash = $(shell git rev-parse HEAD)

.PHONY: help
help: ## Print this help message
	@echo "List of available make commands";
	@echo "";
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}';
	@echo "";

.PHONY: install
install:
	esy install

.PHONY: client-bundle
client-bundle: ## Bundle the JS code
	$(ESY) esbuild _build/default/client/client.js --bundle --outfile=static/--external:melange/lib client.js

.PHONY: client-bundle-watch
client-bundle-watch: ## Watch and bundle the JS code
	esy esbuild _build/default/client/client.js --bundle --outfile=static/client.js --external:melange/lib --watch

.PHONY: client-build
client-build: ## Build Reason code
	$(MEL) build

.PHONY: client-build-watch
client-build-watch: ## Watch reason code
	$(MEL) build --watch

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

.PHONY: clean
clean: ## Clean artifacts
	$(DUNE) clean

.PHONY: format
format: ## Format the codebase with ocamlformat/refmt
	$(DUNE) build @fmt --auto-promote

.PHONY: format-check
format-check: ## Checks if format is correct
	$(DUNE) build @fmt

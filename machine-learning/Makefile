VENV := .venv
PYTHON := $(VENV)/bin/python

.PHONY: setup test lint format pre-commit docs coverage serve-coverage clean help all

install-uv:
	@echo "Installing UV package manager..."
	@curl -LsSf https://astral.sh/uv/install.sh | sh
	@echo "UV installed successfully!"

init_uv:
	@if ! command -v uv >/dev/null 2>&1; then \
		${MAKE} install-uv; \
	fi
	@echo "Initializing UV..."
	@uv init
	@echo "UV initialized successfully!"

setup_uv:
	@if ! command -v uv >/dev/null 2>&1; then \
		${MAKE} install-uv; \
	fi
	@echo "Setting up development environment..."
	@uv venv $(VENV)
	@uv pip install --python $(PYTHON) -e ".[dev]"
	@echo "Development environment setup complete!"

install:
	@uv pip install --python $(PYTHON) -e .

clean:
	@echo "Cleaning build artifacts..."
	@rm -rf build/ dist/ *.egg-info/ .pytest_cache/ .ruff_cache/ .mypy_cache/ htmlcov/ .coverage logs/ workspace/ 
	@rm -rf deep_learning_fundamentals.egg-info/
	@find . -type d -name __pycache__ -exec rm -rf {} +
	@find . -type d -name .ipynb_checkpoints -exec rm -rf {} +

clean_uv:
	@echo "Cleaning UV virtual environment..."
	@rm -rf $(VENV)
	@echo "UV virtual environment cleaned!"

notebook:
	@echo "Checking for Jupyter Notebook..."
	@if ! $(VENV)/bin/pip show notebook > /dev/null 2>&1; then \
		echo "Installing Jupyter Notebook..."; \
		uv pip install --python $(PYTHON) notebook; \
	fi

run_notebook:
	@echo "Running Jupyter Notebook..."
	@$(VENV)/bin/jupyter notebook

setup: setup_uv notebook

help:
	@echo "Enterprise-AI Development Makefile"
	@echo "=================================="
	@echo init_uv       - Initialize UV package manager"
	@echo "setup_uv       - Create virtual env and install deps"
	@echo "setup-browser  - Setup browser automation tools (not implemented)"
	@echo "install        - Install package in dev mode"
	@echo "clean          - Remove build artifacts"
	@echo "clean_uv       - Remove virtual environment"
	@echo "notebook       - Launch Jupyter Notebook"
	@echo "setup          - Setup development environment"

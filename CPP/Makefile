# Simple Makefile for Learning C++23
# ===================================

# VARIABLES
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -g -O0

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
YELLOW = \033[1;33m
NC = \033[0m

# DEFAULT TARGET
.PHONY: help
help:
	@echo "$(BLUE)🎯 Simple C++23 Makefile$(NC)"
	@echo "=========================="
	@echo "$(YELLOW)Usage:$(NC)"
	@echo "  $(GREEN)make run FILE=filename$(NC)  - Compile and run filename.cpp"
	@echo "  $(GREEN)make build FILE=filename$(NC) - Only compile filename.cpp"
	@echo "  $(GREEN)make execute FILE=filename$(NC) - Run already compiled program"
	@echo "  $(GREEN)make clean$(NC)              - Remove all compiled files"
	@echo "  $(GREEN)make list$(NC)               - Show compiled programs"
	@echo ""
	@echo "$(YELLOW)Examples:$(NC)"
	@echo "  make run FILE=main       # Compile and run main.cpp"
	@echo "  make build FILE=hello    # Only compile hello.cpp"
	@echo "  make execute FILE=test   # Run already compiled test"

# Default target (if no FILE specified)
.PHONY: default
default:
	@echo "$(RED)Please specify a file: make run FILE=filename$(NC)"
	@echo "$(BLUE)Available .cpp files:$(NC)"
	@ls -1 *.cpp 2>/dev/null || echo "  No .cpp files found"

# MAIN TARGETS
# ===========

# Compile and run
.PHONY: run
run:
	@if [ -z "$(FILE)" ]; then \
		echo "$(RED)Usage: make run FILE=filename$(NC)"; \
		exit 1; \
	fi
	@if [ ! -f "$(FILE).cpp" ]; then \
		echo "$(RED)Error: $(FILE).cpp not found!$(NC)"; \
		exit 1; \
	fi
	@echo "$(BLUE)🔨 Compiling $(FILE).cpp...$(NC)"
	@mkdir -p build
	@$(CXX) $(CXXFLAGS) $(FILE).cpp -o build/$(FILE)
	@if [ $$? -eq 0 ]; then \
		echo "$(GREEN)✅ Compilation successful!$(NC)"; \
		echo "$(BLUE)🚀 Running $(FILE):$(NC)"; \
		echo "=========================================="; \
		./build/$(FILE); \
		echo "=========================================="; \
		echo "$(GREEN)✅ Program finished$(NC)"; \
	else \
		echo "$(RED)❌ Compilation failed!$(NC)"; \
	fi

# Compile only
.PHONY: build
build:
	@if [ -z "$(FILE)" ]; then \
		echo "$(RED)Usage: make build FILE=filename$(NC)"; \
		exit 1; \
	fi
	@if [ ! -f "$(FILE).cpp" ]; then \
		echo "$(RED)Error: $(FILE).cpp not found!$(NC)"; \
		exit 1; \
	fi
	@echo "$(BLUE)🔨 Compiling $(FILE).cpp...$(NC)"
	@mkdir -p build
	@$(CXX) $(CXXFLAGS) $(FILE).cpp -o build/$(FILE)
	@if [ $$? -eq 0 ]; then \
		echo "$(GREEN)✅ Compilation successful! Executable: build/$(FILE)$(NC)"; \
	else \
		echo "$(RED)❌ Compilation failed!$(NC)"; \
	fi

# Execute already compiled program
.PHONY: execute
execute:
	@if [ -z "$(FILE)" ]; then \
		echo "$(RED)Usage: make execute FILE=filename$(NC)"; \
		exit 1; \
	fi
	@if [ ! -f "build/$(FILE)" ]; then \
		echo "$(RED)Error: build/$(FILE) not found!$(NC)"; \
		echo "$(YELLOW)Compile it first with: make build FILE=$(FILE)$(NC)"; \
		exit 1; \
	fi
	@echo "$(BLUE)🚀 Running $(FILE):$(NC)"
	@echo "=========================================="
	@./build/$(FILE)
	@echo "=========================================="
	@echo "$(GREEN)✅ Program finished$(NC)"

# UTILITY TARGETS
# ==============
.PHONY: clean
clean:
	@echo "$(YELLOW)🧹 Cleaning build directory...$(NC)"
	@rm -rf build/
	@echo "$(GREEN)✅ Clean completed!$(NC)"

.PHONY: list
list:
	@echo "$(BLUE)📋 Available .cpp files:$(NC)"
	@ls -1 *.cpp 2>/dev/null || echo "  No .cpp files found"
	@echo ""
	@echo "$(BLUE)📋 Compiled programs:$(NC)"
	@if [ -d "build" ] && [ -n "$$(ls -A build/ 2>/dev/null)" ]; then \
		ls -1 build/; \
	else \
		echo "  No compiled programs found"; \
	fi

.PHONY: info
info:
	@echo "$(BLUE)📋 Compiler info:$(NC)"
	@echo "Compiler: $(CXX)"
	@echo "Flags: $(CXXFLAGS)"
	@$(CXX) --version | head -1
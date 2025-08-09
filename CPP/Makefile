# Enhanced Makefile for Learning C++23 with Subdirectory Support
# ==============================================================

# VARIABLES
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -g -O0

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
YELLOW = \033[1;33m
CYAN = \033[0;36m
NC = \033[0m

# DEFAULT TARGET
.PHONY: help
help:
	@echo "$(BLUE)🎯 Enhanced C++23 Makefile with Subdirectory Support$(NC)"
	@echo "===================================================="
	@echo "$(YELLOW)Usage:$(NC)"
	@echo " $(GREEN)make run FILE=path/filename$(NC)     - Compile and run path/filename.cpp"
	@echo " $(GREEN)make build FILE=path/filename$(NC)   - Only compile path/filename.cpp"
	@echo " $(GREEN)make execute FILE=path/filename$(NC) - Run already compiled program"
	@echo " $(GREEN)make clean$(NC)                      - Remove all compiled files"
	@echo " $(GREEN)make list$(NC)                       - Show all .cpp files by directory"
	@echo " $(GREEN)make list-dir DIR=dirname$(NC)       - Show .cpp files in specific directory"
	@echo " $(GREEN)make dirs$(NC)                       - Show available directories"
	@echo ""
	@echo "$(YELLOW)Examples:$(NC)"
	@echo " make run FILE=1_first_cpp_program/main"
	@echo " make run FILE=2_variables/exercise"
	@echo " make build FILE=3_functions/calculator"
	@echo " make execute FILE=1_first_cpp_program/main"
	@echo " make list-dir DIR=1_first_cpp_program"

# Default target (if no FILE specified)
.PHONY: default
default:
	@echo "$(RED)Please specify a file: make run FILE=path/filename$(NC)"
	@echo "$(CYAN)Use 'make list' to see available files$(NC)"

# HELPER FUNCTIONS
# ===============

# Extract directory from FILE path
get-dir = $(dir $(1))
# Extract filename without extension from FILE path
get-name = $(notdir $(basename $(1)))
# Get full path without extension
get-path = $(basename $(1))

# MAIN TARGETS
# ===========

# Compile and run
.PHONY: run
run:
	@if [ -z "$(FILE)" ]; then \
		echo "$(RED)Usage: make run FILE=path/filename$(NC)"; \
		echo "$(CYAN)Use 'make list' to see available files$(NC)"; \
		exit 1; \
	fi
	@if [ ! -f "$(FILE).cpp" ]; then \
		echo "$(RED)Error: $(FILE).cpp not found!$(NC)"; \
		echo "$(CYAN)Available files:$(NC)"; \
		find . -name "*.cpp" -type f | sed 's|^\./||' | sed 's|\.cpp$$||' | head -10; \
		exit 1; \
	fi
	@echo "$(BLUE)🔨 Compiling $(FILE).cpp...$(NC)"
	@mkdir -p build/$(call get-dir,$(FILE))
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
		echo "$(RED)Usage: make build FILE=path/filename$(NC)"; \
		echo "$(CYAN)Use 'make list' to see available files$(NC)"; \
		exit 1; \
	fi
	@if [ ! -f "$(FILE).cpp" ]; then \
		echo "$(RED)Error: $(FILE).cpp not found!$(NC)"; \
		echo "$(CYAN)Available files:$(NC)"; \
		find . -name "*.cpp" -type f | sed 's|^\./||' | sed 's|\.cpp$$||' | head -10; \
		exit 1; \
	fi
	@echo "$(BLUE)🔨 Compiling $(FILE).cpp...$(NC)"
	@mkdir -p build/$(call get-dir,$(FILE))
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
		echo "$(RED)Usage: make execute FILE=path/filename$(NC)"; \
		echo "$(CYAN)Use 'make list-compiled' to see compiled programs$(NC)"; \
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

# DIRECTORY AND FILE LISTING
# ==========================

.PHONY: dirs
dirs:
	@echo "$(BLUE)📁 Available directories:$(NC)"
	@find . -type d -name "[0-9]*" | sort | sed 's|^\./||' | while read dir; do \
		count=$$(find "$$dir" -name "*.cpp" 2>/dev/null | wc -l); \
		echo "  $(CYAN)$$dir$(NC) ($$count cpp files)"; \
	done

.PHONY: list
list:
	@echo "$(BLUE)📋 All .cpp files by directory:$(NC)"
	@echo "================================"
	@find . -name "*.cpp" -type f | sed 's|^\./||' | sort | while read file; do \
		dir=$$(dirname "$$file"); \
		base=$$(basename "$$file" .cpp); \
		if [ "$$dir" = "." ]; then \
			echo "$(YELLOW)📄 $$base$(NC)"; \
		else \
			echo "$(CYAN)📁 $$dir/$(NC)$(YELLOW)$$base$(NC)"; \
		fi; \
	done
	@echo ""
	@echo "$(BLUE)💡 Usage example:$(NC)"
	@echo "  make run FILE=1_first_cpp_program/main"

.PHONY: list-dir
list-dir:
	@if [ -z "$(DIR)" ]; then \
		echo "$(RED)Usage: make list-dir DIR=dirname$(NC)"; \
		echo "$(CYAN)Available directories:$(NC)"; \
		find . -type d -name "[0-9]*" | sed 's|^\./||' | sort; \
		exit 1; \
	fi
	@if [ ! -d "$(DIR)" ]; then \
		echo "$(RED)Error: Directory $(DIR) not found!$(NC)"; \
		exit 1; \
	fi
	@echo "$(BLUE)📋 .cpp files in $(DIR):$(NC)"
	@find "$(DIR)" -name "*.cpp" -type f | sed 's|^\./||' | sed 's|\.cpp$$||' | sort | while read file; do \
		echo "  $(YELLOW)$$file$(NC)"; \
	done

.PHONY: list-compiled
list-compiled:
	@echo "$(BLUE)📋 Compiled programs:$(NC)"
	@if [ -d "build" ] && [ -n "$$(find build -type f 2>/dev/null)" ]; then \
		find build -type f | sed 's|^build/||' | sort | while read file; do \
			echo "  $(GREEN)$$file$(NC)"; \
		done; \
	else \
		echo "  No compiled programs found"; \
	fi

# UTILITY TARGETS
# ==============

.PHONY: clean
clean:
	@echo "$(YELLOW)🧹 Cleaning build directory...$(NC)"
	@rm -rf build/
	@echo "$(GREEN)✅ Clean completed!$(NC)"

.PHONY: clean-dir
clean-dir:
	@if [ -z "$(DIR)" ]; then \
		echo "$(RED)Usage: make clean-dir DIR=dirname$(NC)"; \
		exit 1; \
	fi
	@if [ -d "build/$(DIR)" ]; then \
		echo "$(YELLOW)🧹 Cleaning build/$(DIR)...$(NC)"; \
		rm -rf build/$(DIR); \
		echo "$(GREEN)✅ Clean completed for $(DIR)!$(NC)"; \
	else \
		echo "$(YELLOW)No compiled files found for $(DIR)$(NC)"; \
	fi

.PHONY: info
info:
	@echo "$(BLUE)📋 Compiler info:$(NC)"
	@echo "Compiler: $(CXX)"
	@echo "Flags: $(CXXFLAGS)"
	@$(CXX) --version | head -1
	@echo ""
	@echo "$(BLUE)📁 Project structure:$(NC)"
	@tree -I 'build' 2>/dev/null || find . -type d | grep -v build | head -10

# BATCH OPERATIONS
# ===============

.PHONY: build-all
build-all:
	@echo "$(BLUE)🔨 Building all .cpp files...$(NC)"
	@find . -name "*.cpp" -type f | sed 's|^\./||' | sed 's|\.cpp$$||' | while read file; do \
		echo "$(CYAN)Building $$file...$(NC)"; \
		$(MAKE) build FILE="$$file" --silent; \
	done
	@echo "$(GREEN)✅ All files built!$(NC)"

.PHONY: run-all
run-all:
	@echo "$(BLUE)🚀 Running all compiled programs...$(NC)"
	@if [ -d "build" ]; then \
		find build -type f | sed 's|^build/||' | while read file; do \
			echo "$(CYAN)========== Running $$file ==========$(NC)"; \
			./build/$$file; \
			echo ""; \
		done; \
	else \
		echo "$(YELLOW)No compiled programs found. Use 'make build-all' first.$(NC)"; \
	fi
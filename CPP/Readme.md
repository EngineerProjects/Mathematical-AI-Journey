# C++ Learning Journey

Simple and efficient C++23 setup for learning modern C++ from scratch.

## 🚀 Quick Start

```bash
# Compile and run any .cpp file
make run FILE=filename

# Examples
make run FILE=main          # Compile and run main.cpp
make build FILE=hello       # Only compile hello.cpp
make execute FILE=test      # Run already compiled test
```

## 📁 Structure

- `build/` - Compiled executables
- `Makefile` - Simple compilation system
- `*.cpp` - Your C++ source files

## 🛠️ Available Commands

| Command | Description |
|---------|-------------|
| `make help` | Show all available commands |
| `make run FILE=name` | Compile and execute name.cpp |
| `make build FILE=name` | Compile only (no execution) |
| `make execute FILE=name` | Run already compiled program |
| `make clean` | Remove all compiled files |
| `make list` | Show .cpp files and compiled programs |

## ⚙️ Configuration

- **Compiler**: GCC (g++)
- **Standard**: C++23
- **Flags**: `-Wall -Wextra -g -O0` (warnings + debug)

## 🎯 Learning Path

This setup supports the 31-hour C++ course progression:
- Week 1-2: Basics (syntax, variables, functions)
- Week 3-4: Object-Oriented Programming
- Week 5-6: Advanced concepts (STL, templates)
- Week 7: ML/AI applications

Perfect for implementing algorithms from scratch and understanding the mathematics behind machine learning! 🧮
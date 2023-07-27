# Makefile

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c main.h

# Prompt for the file to compile with tab completion
.PHONY: compile
compile:
	@filename=$$(find . -type f -name '*.c' | fzf --prompt="Select a file: "); \
	$(CC) $(CFLAGS) -o output "$$filename"

# Add, commit, and push a file to GitHub
.PHONY: git
git:
	@filename=$$(find . -type f | fzf --prompt="Select a file: "); \
	git add "$$filename"; \
	git commit -m "$$filename"; \
	git push

# Default target
.DEFAULT_GOAL := compile

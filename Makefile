# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# File paths
SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/main
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/cli.c

# Ensure bin directory exists
$(shell mkdir -p $(BIN_DIR))

.PHONY: all clean install

all: $(TARGET)

# Build the final executable
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

clean:
	rm -rf $(BIN_DIR)

install: all
	@echo "Installing to /usr/local/bin (requires sudo)"
	sudo cp $(TARGET) /usr/local/bin/main


# Emulator
# A simple emulator for a instruction set i made up.
# Github: https://www.github.com/lewisevans2007/emulator
# Licence: GNU General Public License v3.0
# By: Lewis Evans


# How to build:
# 1. Run `make config` to create the config file.
# 2. Run `make` to build the emulator.
# 3. Run `make run` to run the emulator.
# 4. Run `make clean` to clean the build files.
# 5. Run `make clean_config` to clean the config file.

# For more infomation see the README.md file.

CC = g++
CFLAGS = -std=c++17
SRC = src/main.cpp
BIN = bin/emulator

all: clean init compile run

config:
	bash build/create_config.bash

init:
	mkdir -p bin
	bash build/check_config_file.bash

compile:
	python3 build/compile_config.py
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

run:
	$(BIN) --version
	$(BIN) examples/add.bin

clean:
	rm -rf bin

clean_config:
	rm -rf .config
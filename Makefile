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
DEFAULT_GOAL := run

# Compiler and Flags
CXX := g++
CXXFLAGS := -std=c++20

# Target and Source Files
TARGET := build/gb-emu
SOURCES := src/main.cpp src/core/memory/Bus.cpp src/core/memory/Cartridge.cpp src/core/memory/IORegisters.cpp
HEADERS := src/core/memory/Bus.hpp src/core/memory/Cartridge.hpp src/core/memory/IORegisters.hpp


run: configure build
	clear
	$(TARGET) roms/game.gb

compile: $(TARGET)

configure:
	cmake -S . -B build

build:
	cmake --build build


clean:
	rm -f $(TARGET)
	rm -rf build/

.PHONY: run compile clean
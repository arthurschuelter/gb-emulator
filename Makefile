DEFAULT_GOAL := run
TARGET := build/gb-emu

run: configure build
	clear
	$(TARGET) roms/game.gb

compile: $(TARGET)

configure:
	cmake -S . -B build

build:
	cmake --build build/

clean:
	rm -rf build/

.PHONY: run build compile clean
.DEFAULT_GOAL := run
TARGET := build/gb-emu

run: configure build
	clear
	$(TARGET) roms/game.gb

compile: $(TARGET)

configure: 
	cmake -S . -B build 
# 	-DGBEMU_ENABLE_CLANG_TIDY=ON

build: configure
	cmake --build build 

clean:
	rm -rf build/

.PHONY: run build compile clean
cmake_minimum_required(VERSION 3.5)

project(GBEmu)

add_executable(gb-emu
    src/main.cpp

    src/core/memory/Bus.cpp
    src/core/memory/Bus.hpp
    src/core/memory/Cartridge.cpp
    src/core/memory/Cartridge.hpp
    src/core/memory/IoRegisters.cpp
    src/core/memory/IoRegisters.hpp

    src/core/cpu/Cpu.cpp
    src/core/cpu/Cpu.hpp
    src/core/cpu/CpuRegisters.cpp
    src/core/cpu/CpuRegisters.hpp
)
cmake_minimum_required(VERSION 3.15)
project(GBEmu)

# set(CMAKE_CXX_CLANG_TIDY clang-tidy)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gb-emu
    src/main.cpp
    src/types.hpp

    src/core/memory/Bus.cpp
    src/core/memory/Bus.hpp
    src/core/memory/Cartridge.cpp
    src/core/memory/Cartridge.hpp
    src/core/memory/CartridgeHeader.cpp
    src/core/memory/CartridgeHeader.hpp
    src/core/memory/IoRegisters.cpp
    src/core/memory/IoRegisters.hpp

    src/core/cpu/Cpu.cpp
    src/core/cpu/Cpu.hpp
    src/core/cpu/CpuRegisters.cpp
    src/core/cpu/CpuRegisters.hpp

    src/frontend/window/Window.cpp
    src/frontend/window/Window.hpp
)

find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)
target_link_libraries(gb-emu sfml-graphics sfml-window sfml-system)
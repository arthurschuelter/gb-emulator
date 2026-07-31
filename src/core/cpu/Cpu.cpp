#include "Cpu.hpp"

#include <iostream>

Cpu::Cpu() {
    registers = std::make_shared<CpuRegisters>();
}
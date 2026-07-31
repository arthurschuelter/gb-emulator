#include "Cpu.hpp"

#include <iostream>

Cpu::Cpu() {
    registers = std::make_shared<CpuRegisters>();
}

Cpu::Cpu(Cpu &obj) {
    registers = obj.registers;
}
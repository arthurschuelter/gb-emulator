#include "Cpu.hpp"

#include <iostream>

Cpu::Cpu(Bus* bus) : bus(bus) {
    this->registers = std::make_shared<CpuRegisters>();
}

void Cpu::powerUp() {
    std::cout << "Start!\n";
}

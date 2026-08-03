#include "Cpu.hpp"

#include <iostream>

Cpu::Cpu(Bus* bus) {
    registers = std::make_shared<CpuRegisters>();
    this->bus = bus;
}

Cpu::Cpu(Cpu &obj) {
    registers = obj.registers;
}

void Cpu::powerUp() {
    // this->bus->busCheck();
    std::cout << "Start!\n";
    uint16_t start = 0x0104;
    uint16_t end = 0x0133;

    for (uint16_t byte = start; byte <= end; byte++) {
        std::cout << std::showbase << std::hex 
            << static_cast<int>(this->bus->read(byte)) << " ";
    }

}
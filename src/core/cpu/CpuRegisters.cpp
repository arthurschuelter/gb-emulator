#include "CpuRegisters.hpp"

CpuRegisters::CpuRegisters() {
    std::cout << "Initializing CPU Registers" << std::endl;
}


uint16_t CpuRegisters::GetBC() {
    return (static_cast<uint16_t>(b) << 8) | c;
}

void CpuRegisters::SetBC(uint16_t value) {
    b = static_cast<uint8_t>(value) >> 8;
    c = static_cast<uint8_t>(value & 0x00FF);
}

// uint16_t CpuRegisters::GetDE();
// void CpuRegisters::SetDE(uint16_t value);

// uint16_t CpuRegisters::GetHL();
// void CpuRegisters::SetHL(uint16_t value);
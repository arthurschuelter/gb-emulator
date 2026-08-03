#include "CpuRegisters.hpp"

CpuRegisters::CpuRegisters() {
    std::cout << "Initializing CPU Registers\n";
}


uint16_t CpuRegisters::GetBC() {
    return (static_cast<uint16_t>(b) << 8) | c;
}

void CpuRegisters::SetBC(uint16_t value) {
    b = static_cast<uint8_t>(value >> 8);
    c = static_cast<uint8_t>(value & 0x00FF);
}

uint16_t CpuRegisters::GetDE() {
    return (static_cast<uint16_t>(d) << 8) | e;
}

void CpuRegisters::SetDE(uint16_t value) {
    d = static_cast<uint8_t>(value >> 8);
    e = static_cast<uint8_t>(value & 0x00FF);
}

uint16_t CpuRegisters::GetHL() {
    return (static_cast<uint16_t>(h) << 8) | l;
}

void CpuRegisters::SetHL(uint16_t value) {
    h = static_cast<uint8_t>(value >> 8);
    l = static_cast<uint8_t>(value & 0x00FF);
}

void CpuRegisters::SetRegisters(uint16_t value, uint8_t &hi, uint8_t &lo) {
    hi = static_cast<uint8_t>(value >> 8);
    lo = static_cast<uint8_t>(value & 0x00FF);
}
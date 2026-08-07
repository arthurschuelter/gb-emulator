#include "CpuRegisters.hpp"

CpuRegisters::CpuRegisters() {
    std::cout << "Initializing CPU Registers\n";
}


u16 CpuRegisters::GetBC() {
    return (static_cast<u16>(b) << 8) | c;
}

void CpuRegisters::SetBC(u16 value) {
    b = static_cast<u8>(value >> 8);
    c = static_cast<u8>(value & 0x00FF);
}

u16 CpuRegisters::GetDE() {
    return (static_cast<u16>(d) << 8) | e;
}

void CpuRegisters::SetDE(u16 value) {
    d = static_cast<u8>(value >> 8);
    e = static_cast<u8>(value & 0x00FF);
}

u16 CpuRegisters::GetHL() {
    return (static_cast<u16>(h) << 8) | l;
}

void CpuRegisters::SetHL(u16 value) {
    h = static_cast<u8>(value >> 8);
    l = static_cast<u8>(value & 0x00FF);
}

void CpuRegisters::SetRegisters(u16 value, u8 &high, u8 &low) {
    high = static_cast<u8>(value >> 8);
    low = static_cast<u8>(value & 0x00FF);
}
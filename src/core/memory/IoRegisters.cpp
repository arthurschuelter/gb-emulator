#include "IoRegisters.hpp"

#include <stdexcept>

IoRegisters::IoRegisters() {
    data.fill(0x00);
}

u8 IoRegisters::read(u16 addr) {
    if (addr == 0xFF00) throw std::invalid_argument("Joypad not implemented yet...");

    throw std::invalid_argument("Not implemented yet...");
}
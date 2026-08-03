#include "IoRegisters.hpp"

#include <stdexcept>

IoRegisters::IoRegisters() {
    data.fill(0x00);
}

uint8_t IoRegisters::read(uint16_t addr) {
    if (addr == 0xFF00) throw std::invalid_argument("Joypad not implemented yet...");

    throw std::invalid_argument("Not implemented yet...");
}
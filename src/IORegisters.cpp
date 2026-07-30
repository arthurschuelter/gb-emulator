#include "IORegisters.hpp"

#include <stdexcept>

IORegisters::IORegisters() {
    data.fill(0x00);
}

uint8_t IORegisters::read(uint16_t addr) {
    if (addr == 0xFF00) throw std::invalid_argument("Joypad not implemented yet...");

    throw std::invalid_argument("Not implemented yet...");
}
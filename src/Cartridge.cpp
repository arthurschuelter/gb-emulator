#include "Cartridge.hpp"

#include <stdexcept>

Cartridge::Cartridge() {
    rom.fill(0x00);
    eram.fill(0x00);
}

uint8_t Cartridge::read(uint16_t addr) {
    if (addr >= 0xA000) {
        return eram[addr - 0xA000];
    }
    return rom[addr];
}
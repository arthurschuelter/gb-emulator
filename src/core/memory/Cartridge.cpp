#include "Cartridge.hpp"

#include <iostream>
#include <stdexcept>

Cartridge::Cartridge(std::ifstream &file) {
    rom.fill(0x00);
    eram.fill(0x00);

    // std::cout << "Cartridge: " << std::showbase << std::hex << file.peek() <<  "\n";

    _rom = std::vector<uint8_t>(
        std::istream_iterator<uint8_t>(file), 
        std::istream_iterator<uint8_t>()
    );
}

uint8_t Cartridge::read(uint16_t addr) {
    if (addr >= 0xA000) {
        return eram[addr - 0xA000];
    }
    return _rom[addr];
}
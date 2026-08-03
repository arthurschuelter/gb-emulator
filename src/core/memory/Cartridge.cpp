#include "Cartridge.hpp"

#include <iostream>
#include <stdexcept>
#include <filesystem>

Cartridge::Cartridge(std::ifstream &file) {
    eram.fill(0x00);
    
    rom = loadRom(file);

    header = new CartridgeHeader(rom);
    header->printHeaderInfo();
}

uint8_t Cartridge::read(uint16_t addr) {
    if (addr >= 0xA000) {
        return eram[addr - 0xA000];
    }
    return rom[addr];
}

std::vector<uint8_t>& Cartridge::loadRom(std::ifstream &file) {
    file.seekg(0, std::ios::end);
    auto fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    rom = std::vector<uint8_t>(fileSize);

    for (uint16_t byte = 0; byte < fileSize; byte++) {
        rom[byte] = file.get();
    }

    return rom;
}
#include "Cartridge.hpp"

#include <iostream>
#include <stdexcept>
#include <filesystem>

Cartridge::Cartridge(std::ifstream &file) {
    eram.fill(0x00);
    
    rom = loadRom(file);

    header = new CartridgeHeader(rom);
    // header->printHeaderInfo();
}

u8 Cartridge::read(u16 addr) {
    if (addr >= 0xA000) {
        return eram[addr - 0xA000];
    }
    return rom[addr];
}

std::vector<u8>& Cartridge::loadRom(std::ifstream &file) {
    file.seekg(0, std::ios::end);
    auto fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    rom = std::vector<u8>(fileSize);

    for (u16 byte = 0; byte < fileSize; byte++) {
        rom[byte] = file.get();
    }

    return rom;
}
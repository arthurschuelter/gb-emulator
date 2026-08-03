#pragma once

#include "CartridgeHeader.hpp"

#include <array>
#include <fstream>
#include <memory>
#include <vector>
#include <iterator>

class Cartridge {
public:
    Cartridge(std::ifstream &file);
    ~Cartridge() = default;

    uint8_t read(uint16_t addr);
    
    private:
    std::vector<uint8_t> rom;
    std::array<uint8_t, 0x2000> eram;
    CartridgeHeader* header;
    
    std::vector<uint8_t>& loadRom(std::ifstream &file);
};
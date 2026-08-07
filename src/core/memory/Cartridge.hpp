#pragma once

#include "../../types.hpp"
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

    u8 read(u16 addr);
    
    private:
    std::vector<u8> rom;
    std::array<u8, 0x2000> eram;
    CartridgeHeader* header;
    
    std::vector<u8>& loadRom(std::ifstream &file);
};
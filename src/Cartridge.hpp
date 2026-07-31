#pragma once

#include <array>
#include <fstream>
#include <memory>
#include <vector>
#include <iterator>

class  Cartridge {
public:
    Cartridge(std::ifstream &file);
    ~Cartridge() = default;

    uint8_t read(uint16_t addr);
    void loadRom(std::ifstream &file);

private:
    // maybe change to vector
    std::array<uint8_t, 0x8000> rom;
    std::vector<uint8_t> _rom;
    std::array<uint8_t, 0x2000> eram;

};
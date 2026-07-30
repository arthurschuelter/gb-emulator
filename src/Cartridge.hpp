#pragma once

#include <array>
#include <memory>

class  Cartridge {
public:
    Cartridge();
    ~Cartridge() = default;

    uint8_t read(uint16_t addr);

private:
    // maybe change to vector
    std::array<uint8_t, 0x8000> rom;
    std::array<uint8_t, 0x2000> eram;

};
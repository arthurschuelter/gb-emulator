#pragma once

#include <array>
#include <memory>

class Cartridge;

class Bus {
public:
    Bus();
    ~Bus() = default;

    uint8_t read(uint16_t addr);
    void write(uint16_t addr, uint8_t value);

private:
    std::shared_ptr<Cartridge> cartridge;   // 0000--3FFF

    std::array<uint8_t, 0x2000> vram;       // 8000--9FFF
    std::array<uint8_t, 0x2000> eram;       // A000--BFFF
    std::array<uint8_t, 0x2000> wram;       // C000--DFFF

    std::array<uint8_t,   0x7F> hram;       // FF00--FFFE
    
    uint8_t interrupt_enable{0};            // FFFF--FFFF
};
#pragma once

#include "Cartridge.hpp"
#include "IoRegisters.hpp"

#include <array>
#include <memory>

class Bus {
public:
    Bus(Cartridge* _cartridge);
    ~Bus() = default;
    Bus(Bus &obj);

    uint8_t read(uint16_t addr);
    void write(uint16_t addr, uint8_t value);

    // Testing
    void BusCheck();

private:
    Cartridge* cartridge;               // 0000--3FFF
                                        // 4000--7FFF
    std::array<uint8_t, 0x2000> eram;   // A000--BFFF


    std::array<uint8_t, 0x2000> vram;   // 8000--9FFF
    std::array<uint8_t, 0x2000> wram;   // C000--DFFF
    std::array<uint8_t,   0xA0> oam;    // FE00--FE9F

    std::shared_ptr<IoRegisters> io;    // FF00--FF7F
    std::array<uint8_t,   0x7F> hram;   // FF80--FFFE
    uint8_t interrupt_enable{0};        // FFFF--FFFF
};
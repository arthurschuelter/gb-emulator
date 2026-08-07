#pragma once

#include "../../types.hpp"

#include "Cartridge.hpp"
#include "IoRegisters.hpp"

#include <array>
#include <memory>

class Bus {
public:
    Bus(Cartridge* _cartridge);
    ~Bus() = default;
    Bus(Bus &obj);

    u8 read(u16 addr);
    void write(u16 addr, u8 value);

    // Testing
    void busCheck();

private:
    Cartridge* cartridge;               // 0000--3FFF
                                        // 4000--7FFF
    std::array<u8, 0x2000> eram;   // A000--BFFF


    std::array<u8, 0x2000> vram;   // 8000--9FFF
    std::array<u8, 0x2000> wram;   // C000--DFFF
    std::array<u8,   0xA0> oam;    // FE00--FE9F

    std::shared_ptr<IoRegisters> io;    // FF00--FF7F
    std::array<u8,   0x7F> hram;   // FF80--FFFE
    u8 interrupt_enable{0};        // FFFF--FFFF
};
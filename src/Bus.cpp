#include "Bus.hpp"
#include <iostream>
#include <stdexcept>

Bus::Bus() {
    vram.fill(0x00);
    eram.fill(0x00);
    wram.fill(0x00);
    hram.fill(0x00);
    oam.fill(0x00);

    cartridge = std::make_shared<Cartridge>();
}

uint8_t Bus::read(uint16_t addr) {
    try {
        // if (addr <= 0x7FFF || (addr >= 0xA000 && addr <= 0xBFFF)) return cartridge->read(addr);
        if (addr <= 0x7FFF) return cartridge->read(addr);
        if (addr <= 0x9FFF) return vram[addr - 0x8000];
        if (addr <= 0xBFFF) return cartridge->read(addr);
        if (addr <= 0xDFFF) return wram[addr - 0xC000];
        if (addr <= 0xFDFF) return read(addr - 0x2000);
        if (addr <= 0xFE9F) return oam[addr - 0xFE00];
        if (addr <= 0xFEFF) return 0xFF;
        if (addr <= 0xFF7F) throw std::invalid_argument("IORegisters not implemented yet..."); // return ioRegisters->read(addr - 0xFF00)
        if (addr <= 0xFFFE) return hram[addr - 0xFF80];
        if (addr == 0xFFFF) return interrupt_enable;
        
        
        throw std::invalid_argument("Not implemented yet...");
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what();
    }
    return 0;
}

void Bus::write(uint16_t addr, uint8_t value) {

}
#include "Bus.hpp"
#include <iostream>
#include <stdexcept>

Bus::Bus() {
    vram.fill(0x00);
    eram.fill(0x00);
    wram.fill(0x00);
    hram.fill(0x00);
}

uint8_t Bus::read(uint16_t addr) {
    try {
        if (addr <= 0x7FFF || (addr >= 0xA000 && addr <= 0xBFFF)) {
            // return cartridge->read(addr);
        } else if (addr >= 0x8000 && addr <= 0x9FFF) {
            return vram[addr - 0x8000];
        } else {
            throw std::invalid_argument("Not implemented yet...");
        }
        
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what();
    }
    return 0;
}

void Bus::write(uint16_t addr, uint8_t value) {

}
#include "Bus.hpp"

#include <iostream>
#include <stdexcept>

Bus::Bus(Cartridge* _cartridge) : cartridge(_cartridge) {
    vram.fill(0x00);
    eram.fill(0x00);
    wram.fill(0x00);
    hram.fill(0x00);
    oam.fill(0x00);

    io = std::make_shared<IoRegisters>();
    
    BusCheck();
}

uint8_t Bus::read(uint16_t addr) {
    try {
        if (addr <= 0x7FFF) return cartridge->read(addr);
        if (addr <= 0x9FFF) return vram[addr - 0x8000];
        if (addr <= 0xBFFF) return cartridge->read(addr);
        if (addr <= 0xDFFF) return wram[addr - 0xC000];
        if (addr <= 0xFDFF) return read(addr - 0x2000);
        if (addr <= 0xFE9F) return oam[addr - 0xFE00];
        if (addr <= 0xFEFF) return 0xFF;
        if (addr <= 0xFF7F) return io->read(addr);
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

void Bus::BusCheck() {
    std::cout << "VRAM:\t" << read(0x8000) << "\n";
    std::cout << "WRAM:\t" << read(0xC000) << "\n";
    std::cout << "HRAM:\t" << read(0xFF80) << "\n";
    std::cout << "OAM:\t" << read(0xFE00) << "\n";
    std::cout << "Echo RAM:\t" << read(0xE000) << "\n";
    std::cout << "Interrupt Enable:\t" << read(0xFFFF) << "\n";
    
    std::cout << "Cartridge A:\t" << std::showbase << std::hex 
        << static_cast<int>(read(0x0000)) << "\n";
    std::cout << "Cartridge B:\t" << std::showbase << std::hex 
        << static_cast<int>(read(0x4000)) << "\n";
    std::cout << "ERAM:\t" << read(0xA000) << "\n";
    std::cout << "I/O Registers:\t" << read(0xFF00) << "\n";
    
    std::cout << "Not Usable:\t" << static_cast<int>(read(0xFEA0)) << "\n";

}
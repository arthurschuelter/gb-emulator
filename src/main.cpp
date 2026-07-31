#include <fstream>
#include <iostream>

#include "Bus.hpp"

void BusCheck(Bus* bus) {
    // std::cout << "VRAM:\t" << bus->read(0x8000) << std::endl;
    // std::cout << "WRAM:\t" << bus->read(0xC000) << std::endl;
    // std::cout << "HRAM:\t" << bus->read(0xFF80) << std::endl;
    // std::cout << "OAM:\t" << bus->read(0xFE00) << std::endl;
    // std::cout << "Echo RAM:\t" << bus->read(0xE000) << std::endl;
    // std::cout << "Interrupt Enable:\t" << bus->read(0xFFFF) << std::endl;
    
    std::cout << "Cartridge A:\t" << std::showbase << std::hex 
           << static_cast<int>(bus->read(0x0000)) << std::endl;
    std::cout << "Cartridge B:\t" << std::showbase << std::hex 
           << static_cast<int>(bus->read(0x4000)) << std::endl;
    // std::cout << "ERAM:\t" << bus->read(0xA000) << std::endl;
    // std::cout << "I/O Registers :\t" << bus->read(0xFF00) << std::endl;
    
    // std::cout << "Not Usable:\t" << bus->read(0xFEA0) << std::endl;

}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "No game detected..." << std::endl;
        return 0;
    }

    std::string filename = argv[1];
    std::cout << "Loading: " << filename  << std::endl;
    
    std::ifstream file(filename, std::ios::binary);
    
    if (!file.is_open()) {
        std::cout << "Failed to open file..." << std::endl;
        return 0;
    }

    Cartridge* cartridge = new Cartridge(file);
    Bus* bus = new Bus(cartridge);
    BusCheck(bus);

    file.close();
    return 0;
}
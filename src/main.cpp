#include <iostream>
#include "Bus.hpp"

void BusCheck(Bus* bus) {
    std::cout << "VRAM:\t" << bus->read(0x8000) << std::endl;
    std::cout << "WRAM:\t" << bus->read(0xC000) << std::endl;
    std::cout << "HRAM:\t" << bus->read(0xFF80) << std::endl;
    std::cout << "OAM:\t" << bus->read(0xFE00) << std::endl;
    std::cout << "Echo RAM:\t" << bus->read(0xE000) << std::endl;
    std::cout << "Interrupt Enable:\t" << bus->read(0xFFFF) << std::endl;
    
    std::cout << "Cartridge A:\t" << bus->read(0x0000) << std::endl;
    std::cout << "Cartridge B:\t" << bus->read(0x4000) << std::endl;
    std::cout << "ERAM:\t" << bus->read(0xA000) << std::endl;
    std::cout << "I/O Registers :\t" << bus->read(0xFF00) << std::endl;
    
    std::cout << "Not Usable:\t" << bus->read(0xFEA0) << std::endl;

}

int main(int argc, char* argv[]) {
    Bus* bus = new Bus();
    std::cout << "Hello, World!" << std::endl;

    BusCheck(bus);

    return 0;
}
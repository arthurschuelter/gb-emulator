#include <iostream>
#include "Bus.hpp"

void BusCheck(Bus* bus) {
    std::cout << "VRAM: " << bus->read(0x8000) << std::endl;
    std::cout << "ERAM: " << bus->read(0xA000) << std::endl;
    std::cout << "WRAM: " << bus->read(0xC000) << std::endl;
    std::cout << "HRAM: " << bus->read(0xFF00) << std::endl;

}

int main(int argc, char* argv[]) {
    Bus* bus = new Bus();
    std::cout << "Hello, World!" << std::endl;

    BusCheck(bus);

    return 0;
}
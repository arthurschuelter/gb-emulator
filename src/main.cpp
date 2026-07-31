#include <fstream>
#include <iostream>

#include "./core/memory/Bus.hpp"
#include "./core/cpu/Cpu.hpp"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "No game detected...\n";
        return 0;
    }

    std::string filename = argv[1];
    std::cout << "Loading: " << filename  << "\n";
    
    std::ifstream file(filename, std::ios::binary);
    
    if (!file.is_open()) {
        std::cout << "Failed to open file...\n";
        return 0;
    }

    Cpu* cpu = new Cpu();
    Cartridge* cartridge = new Cartridge(file);
    Bus* bus = new Bus(cartridge);
    // BusCheck(bus);


    std::cout << (0xFF == 0x00FF) << "\n"; 

    file.close();
    return 0;
}
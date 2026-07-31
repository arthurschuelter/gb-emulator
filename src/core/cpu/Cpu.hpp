#pragma once

#include <iostream>

class Cpu {
public:
    Cpu();
    ~Cpu() = default;

private:
    uint16_t AF;
    uint16_t BC;
    uint16_t DE;
    uint16_t HL;
    uint16_t SP;
    uint16_t PC;

};
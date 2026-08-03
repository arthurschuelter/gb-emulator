#pragma once

#include <iostream>
#include <cstdint>

class CpuRegisters {
public:
    CpuRegisters();
    ~CpuRegisters() = default;

    uint16_t GetBC();
    void SetBC(uint16_t value);

    uint16_t GetDE();
    void SetDE(uint16_t value);

    uint16_t GetHL();
    void SetHL(uint16_t value);

    void SetRegisters(uint16_t value, uint8_t &high, uint8_t &low);

private:
    uint8_t a{0};
    uint8_t b{0};
    uint8_t c{0};
    uint8_t d{0};
    uint8_t e{0};
    uint8_t f{0};
    uint8_t h{0};
    uint8_t l{0};
    
    uint16_t sp{0};
    uint16_t pc{0};
};
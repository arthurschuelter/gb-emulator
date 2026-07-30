#pragma once

#include <array>
#include <memory>

class IORegisters {

public:
    IORegisters();
    ~IORegisters() = default;

    uint8_t read(uint16_t addr);

private:
    std::array<uint8_t, 0x80> data;
};
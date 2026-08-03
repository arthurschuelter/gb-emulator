#pragma once

#include <array>
#include <memory>

class IoRegisters {

public:
    IoRegisters();
    ~IoRegisters() = default;

    uint8_t read(uint16_t addr);

private:
    std::array<uint8_t, 0x80> data;
};
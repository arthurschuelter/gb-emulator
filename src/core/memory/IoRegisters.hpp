#pragma once

#include "../../types.hpp"

#include <array>
#include <memory>

class IoRegisters {

public:
    IoRegisters();
    ~IoRegisters() = default;

    u8 read(u16 addr);

private:
    std::array<u8, 0x80> data;
};
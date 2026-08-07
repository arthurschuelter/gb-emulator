#pragma once

# include "../../types.hpp"

#include <iostream>
#include <cstdint>

class CpuRegisters {
public:
    CpuRegisters();
    ~CpuRegisters() = default;

    u16 GetBC();
    void SetBC(u16 value);

    u16 GetDE();
    void SetDE(u16 value);

    u16 GetHL();
    void SetHL(u16 value);

    void SetRegisters(u16 value, u8 &high, u8 &low);

private:
    u8 a = 0, f = 0;
    u8 b = 0, c = 0;
    u8 d = 0, e = 0;
    u8 h = 0, l = 0;
    
    u16 sp = 0;
    u16 pc = 0;
};
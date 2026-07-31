#pragma once

#include <iostream>

#include "CpuRegisters.hpp"

class Cpu {
public:
    Cpu();
    ~Cpu() = default;

private:
    std::shared_ptr<CpuRegisters> registers;
};
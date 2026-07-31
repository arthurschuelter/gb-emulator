#pragma once

#include <iostream>

#include "CpuRegisters.hpp"

class Cpu {
public:
    Cpu();
    ~Cpu() = default;
    Cpu(Cpu &obj);

private:
    std::shared_ptr<CpuRegisters> registers;
};
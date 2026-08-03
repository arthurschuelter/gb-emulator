#pragma once

#include <iostream>
#include <memory>

#include "CpuRegisters.hpp"
#include "../memory/Bus.hpp"

class Cpu {
public:
    Cpu(Bus* bus);
    ~Cpu() = default;
    Cpu(Cpu &obj);

    void powerUp();

private:
    std::shared_ptr<CpuRegisters> registers;
    Bus* bus;
};
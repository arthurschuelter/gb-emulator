#pragma once

#include <iostream>
#include <memory>

#include "CpuRegisters.hpp"
#include "../memory/Bus.hpp"

class Cpu {
public:
    Cpu(Bus* bus);
    ~Cpu() = default;
    Cpu(Cpu &obj) = default;
    Cpu(Cpu &&obj) noexcept = default;

    Cpu& operator=(Cpu &obj) = default;
    Cpu& operator=(Cpu &&obj) noexcept = default;

    void powerUp();
    void loop();

private:
    std::shared_ptr<CpuRegisters> registers;
    Bus* bus;
};
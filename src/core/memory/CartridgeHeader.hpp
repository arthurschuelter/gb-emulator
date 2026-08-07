#pragma once

#include "../../types.hpp"

#include <array>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class CartridgeHeader {
public:
    CartridgeHeader(std::vector<u8> &rom);
    ~CartridgeHeader() = default;

    void printHeaderInfo();

private:
    std::array<u8, 0x30> nintendo_logo;
    std::array<u8, 0x10> title;
    std::array<u8, 0x03> manufacturer_code;
    u8 licensee_code;
    std::string licensee_name;

    u8 cgb_flag;
    u8 sgb_flag;
    u8 cartridge_type;
    u8 rom_size;
    u8 ram_size;
    u8 destination_code;
    u8 mask_rom_version_number;

    u8 header_checksum;
    u16 global_checksum;

    std::string getLicensee(u8 code, bool isNewLicensee);
};
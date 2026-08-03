#pragma once

#include <array>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class CartridgeHeader {
public:
    CartridgeHeader(std::vector<uint8_t> &rom);
    ~CartridgeHeader() = default;

    void printHeaderInfo();

private:
    std::array<uint8_t, 0x30> nintendo_logo;
    std::array<uint8_t, 0x10> title;
    std::array<uint8_t, 0x03> manufacturer_code;
    uint8_t licensee_code;
    std::string licensee_name;

    uint8_t cgb_flag;
    uint8_t sgb_flag;
    uint8_t cartridge_type;
    uint8_t rom_size;
    uint8_t ram_size;
    uint8_t destination_code;
    uint8_t mask_rom_version_number;

    uint8_t header_checksum;
    uint16_t global_checksum;

    std::string getLicensee(uint8_t code, bool isNewLicensee);
};
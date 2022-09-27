#include <iostream>

uint32_t GetBitsFromUint32(uint32_t, uint8_t, uint8_t);

int main()
{
    uint32_t res = GetBitsFromUint32(0xABCDEF12, 4, 12);
    std::cout << "--------- ZADANIE 1 --------- \nres="
              << "0x" << std::hex << res << std::endl;
    return 0;
}
uint32_t GetBitsFromUint32(uint32_t inputValue, uint8_t bitLength, uint8_t bitOffset)
{
    uint32_t output = (inputValue >> (bitLength)) & ((1 << bitOffset) - 1);
    return output;
}

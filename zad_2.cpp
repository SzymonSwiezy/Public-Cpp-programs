#include <iostream>
#include <string.h>
uint32_t GetBitsFromUint32(const char *, uint8_t, uint8_t);

int main()
{
    std::cout << "--------- ZADANIE 2 --------- \nres=";
    uint32_t res = GetBitsFromUint32("0xABCDEF12", 4, 12);
    std::cout << std::hex << res;
    return 0;
}
uint32_t GetBitsFromUint32(const char *imputValue, uint8_t bitOffset, uint8_t bitLength)
{
    uint32_t len = strlen(imputValue), base = 1, temp = 0;
    for (int i = (len - 1); i >= 0; i--)
    {
        if (imputValue[i] >= '0' && imputValue[i] <= '9')
        {
            temp += (imputValue[i] - '0') * base;
            base *= 16;
        }
        else if (imputValue[i] >= 'A' && imputValue[i] <= 'F')
        {
            temp += (imputValue[i] - 55) * base;
            base *= 16;
        }
    }

    return (temp >> (bitOffset)) & ((1 << bitLength) - 1);
}
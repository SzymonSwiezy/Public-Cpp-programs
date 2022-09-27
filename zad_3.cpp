#include <iostream>
#include <vector>
#include <sstream>

std::vector<bool> GetBitsVector(std::string);

int main()
{
    std::cout << "--------- ZADANIE 3 --------- \nres=";
    std::vector<bool> res = GetBitsVector("0x95");
    for (int i = 0; i < res.size(); i++)
        std::cout << res[i];
    return 0;
}
std::vector<bool> GetBitsVector(std::string inputValue)
{
    std::stringstream j;
    uint32_t uint32Size;
    std::vector<bool> output;
    j << std::hex << inputValue;
    while (j >> uint32Size)
    {
        for (int i = sizeof(inputValue) - 1; i >= 0; i--)
            output.push_back(((uint32Size >> i) & 1) ? true : false);
    }

    return output;
}

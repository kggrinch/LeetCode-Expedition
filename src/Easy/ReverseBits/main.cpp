#include <cstdint>
#include <iostream>

// Time Complexity: O(1) - 32
// Space Complexity: O(1) - 32 bits
int reverseBits(std::uint32_t n)
{
    std::uint32_t result = 0; // 000...
    for (int i = 0; i < 32; i++)
    {
        // get the bit at position i, starts at beginning
        std::uint32_t position = n >> i;
        std::uint32_t bit = position & 1;

        // place the retrieved bit at reverse position of i
        std::uint32_t reverse_position = bit << (31 - i);
        result = result | reverse_position;
    }
    return result;
}

int main()
{
    std::cout << reverseBits( 00000000000000000000000000010101) << "\n";
}
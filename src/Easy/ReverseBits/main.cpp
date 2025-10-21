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
        std::uint32_t bit = position & 1; // extract lsb

        // place the retrieved bit at reverse position of i
        std::uint32_t reverse_position = bit << (31 - i); // shift extracted a bit left to correct reverse position
        result = result | reverse_position; // add extracted bit in correct position into the result
    }
    return result;
}

int main()
{
    std::cout << reverseBits( 1001) << "\n";
}
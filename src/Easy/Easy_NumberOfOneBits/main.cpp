#include <iostream>
#include <cstdint>
#include <bitset>
#include <string>

// Brute Force
// Time Complexity: O(1) n limit (not including conversions)
// Space Complexity: O(1)
int hammingWeight(std::uint32_t n)
{
    // 1, 2, 4, 8, 16, 32, 64, ... 4294967296
    // 0, 1, 2, 3, 4,  5,  6, ... 32

    // Convert value into binary
    // count number of 1 sets
    int count{};
    std::string s_n = std::bitset<32>(n).to_string();
    for(char c : s_n)
    {
        if(c == '1') count++;
    }
    return count;
}

// Real Solution (not optimized but how it should be solved)
// Time Complexity: O(1)
// Space Complexity: O(1)
int hammingWeight_real(std::uint32_t n)
{
    // Iterate through each bit seeing if the very left bit is a 1 or 0.
    // To figure out if it's a 1 or 0 we can either & or % 2 the value
    //  * If 0101 & 0001 = 0001 | 0101 % 2 = 0001 so the very left bit is a 1 increase count
    //  * If 0100 & 0001 = 0000 | 0100 % 2 = 0000 so the very left bit is a 0 skip
    // This just checks the left value so now we need to move the bits to check the rest.
    // To move the bits shift them to left. You can either use a left shift operation or divide by 2
    int count{};
    while (n > 0)
    {
        count += n & 1; // and operation
        // Or
        // count += n % 2;
        n = n >> 1; // shift left 1 bit
    }
    return count;
}
// Optimized solution
// Time Complexity: O(1)
// Space Complexity: O(1)
int hammingWeight_optimized(std::uint32_t n)
{
    // Optimized solution gets rid of iterating through each bit
    // How it works:
    //  n & (n - 1) - this formula gets rid of one set a bit at a time
    int count{};
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{

    std::cout << hammingWeight_optimized(011) << "\n";

    return 0;
}



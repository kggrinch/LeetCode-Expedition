#include <iostream>
#include <vector>

// Brute Force
// Time Complexity: n log n
// Space Complexity: O(n) - result of n + 1
std::vector<int> countBits(int n)
{
    std::vector<int> result(n + 1);
    // Iterate through each value and count the number of 1 set bits in the current value
    for (int i = 0; i <= n; i++) // n
    {
        int count{};
        int p = i;
        while(p) // counting only 1 set bits | log n dividing by 2 each time
        {
            p = p & (p - 1);
            count++;
        }
        result[i] = count;
    }
    return result;
}

// Optimized Solution | dynamic programming
// Time Complexity: O(n)
// Space Complexity: O(n) - result of n + 1
std::vector<int> countBits_optimized(int n)
{
    std::vector<int> result;
    std::vector<int> cache(n + 1, -1);
    int msb{1}; // most significant bit
    cache[0] = 0;
    result.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if ( (msb * 2) == i) msb = i; // check if we reached a msb
        cache[i] = 1 + cache[i - msb];
        result.push_back(cache[i]);
    }
    return result;
}


int main()
{
    std::vector<int> result = countBits(2);
    std::vector<int> result2 = countBits_optimized(5);
    return 0;
}

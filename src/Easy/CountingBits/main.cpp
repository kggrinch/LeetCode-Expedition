#include <iostream>
#include <vector>

// Brute Force
// Time Complexity: n log n
// Space Complexity: O(n) - result of n + 1
std::vector<int> countBits(int n)
{
    std::vector<int> result(n + 1);
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

// Optimized Solution
// Time Complexity: n log n
// Space Complexity: O(n) - result of n + 1
std::vector<int> countBits_optimzed(int n)
{

}


int main()
{
    std::vector<int> result = countBits(2);
    int x;
    return 0;
}

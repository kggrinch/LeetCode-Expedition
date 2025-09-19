#include <iostream>
#include <unordered_map>
#include <map>


// Time Complexity: O(n) - n problem is generated once
// Space Complexity: O(n) - map holds n inputs
int fib_memoization(const int& n, std::unordered_map<int, int>& map)
{
    if(n <= 1) return 1;
    if(map.count(n) == 1) map[n];
    map[n] = fib_memoization(n - 1, map) + fib_memoization(n - 2, map);
    return map[n];
}

// Time Complexity: O(n) - n subproblem is generated once
// Space Complexity: O(n) - map holds n inputs
int climbStairs_memoization(const int& n)
{
    std::unordered_map<int, int> map;
    return fib_memoization(n, map);
}

// Time Complexity: O(n) - n problem is generated once
// Space Complexity: O(n) - map holds n inputs
int climbStairs_tabulation(const int& n)
{
    if(n <= 1) return 1;
    std::unordered_map<int, int> cache;

    cache[0] = 1;
    cache[1] = 1;

    for(int i = 2; i < n + 1; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[n];
}

// Optimized memory of O(1)
// Time Complexity: O(n)
// Space Complexity: O(1)
int climbStairs_tabulation_optimized(const int& n)
{
    if(n <= 1) return 1;

    long one = 1;
    long two = 1;

    for(int i = 0; i < n; i++)
    {
        long temp = one;
        one = two;
        two = two + temp;
    }

    return one;
}





int main()
{
    int n = 5;
    std::cout << climbStairs_tabulation_optimized(n) << "\n";
    return 0;
}

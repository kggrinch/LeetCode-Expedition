#include <iostream>
#include <vector>
#include <set>

// Brute Force
// Time Complexity: O(n)
// Space Complexity: O(n)
int firstMissingPositive(std::vector<int>& nums)
{
    int n = nums.size();
    std::set<int> cache;
    for (auto v : nums)
    {
        cache.insert(v);
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (cache.count(i) != 1) return i;
    }
    return n + 1;
}

int firstMissingPositive_optimized(std::vector<int>& nums)
{

}


int main()
{
    std::vector<int> nums = {1,2,0};
    std::cout << firstMissingPositive(nums) << std::endl;
    return 0;
}
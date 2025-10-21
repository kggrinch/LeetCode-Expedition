#include <algorithm>
#include <iostream>
#include <vector>

// Brute Force
// Time Complexity: O(n)
// Space Complexity: O(n)
int missingNumber(std::vector<int>& nums)
{
    int n = nums.size();

    // If size value is not in array then that's the value missing
    // If 0 is not in the array then that's the missing value
    if (std::find(nums.begin(), nums.end(), n) == nums.end()) return n;
    if (std::find(nums.begin(), nums.end(), 0) == nums.end()) return 0;

    // check which values are in nums
    std::vector<bool> set(n + 1, false);
    for (int num : nums)
    {
        set[num] = true;
    }

    // find missing value and return
    for (int i = 0; i < n; ++i)
    {
        if (!set[i]) return i;
    }

    return 0; // should not reach here if there is a missing value
}

// Optimized Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
int missingNumber_optimized(std::vector<int>& nums)
{
    // Solution: sum(range) - sum(nums) = missing value
    int n = nums.size();

    int n_sum{};
    int r_sum{};
    for (int num : nums)
    {
        n_sum += num;
    }
    for (int i = 0; i <= n; ++i)
    {
        r_sum += i;
    }

    return r_sum - n_sum;
}

int main()
{
    std::vector<int> nums = {3,0,1};
    std::cout << missingNumber_optimized(nums)<< std::endl;
    return 0;
}
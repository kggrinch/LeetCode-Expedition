#include <iostream>
#include <vector>

// Recursive Brute Force Approach
// Time Complexity: O(n^n)
// Space Complexity: O(1)
bool canJump_recursion(std::vector<int>& nums)
{
    int target = nums.size() - 1;
    auto dfs = [&](int i, auto& dfs) -> bool
    {
        int distance = target - i;
        if (nums[i] >= distance) return true;
        // visit all i's jump paths
        for (int j = i + 1; j <= i + nums[i]; j++)
        {
            if (dfs(j, dfs)) return true;
        }
        return false;
    };

    return dfs(0, dfs);
}

// Memoization Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
bool canJump_memoization(std::vector<int>& nums)
{
    int target = nums.size() - 1;
    std::vector<int> cache(nums.size(), -1);

    auto dfs = [&](int i, auto& dfs) -> bool
    {
        if (cache[i] != -1) return cache[i];
        int distance = target - i;
        if (nums[i] >= distance) return true;
        for (int j = i + 1; j <= nums[i] + i; j++)
        {
            cache[j] = dfs(j, dfs);
            if (cache[j]) return true;
        }
        return false;
    };
    return dfs(0, dfs);
}

// Tabulation Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
bool canJump_tabulation(std::vector<int>& nums)
{
    int target = nums.size() - 1;
    std::vector<bool> cache(nums.size(), false);;
    cache[target] = true;
    // Start from the index before the target and check if valid before moving down
    for (int i = target - 1; i >= 0; --i)
    {
        for (int j = i + 1; j <= i + nums[i]; j++) // Loop through all i's jump possibility
        {
            if (cache[j])
            {
                cache[i] = true;
                break;
            }
        }
    }
    return cache[0];
}

// Greedy Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
bool canJump_greedy(std::vector<int>& nums)
{
    int target = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        int distance = target - i;
        if (nums[i] >= distance) target = i;
    }
    return target == 0;
}

int main()
{
    std::vector<int> nums = {2,3,1,0,4};
    std::cout << canJump_recursion(nums) << "\n";
    std::cout << canJump_memoization(nums) << "\n";
    std::cout << canJump_tabulation(nums) << "\n";
    std::cout << canJump_greedy(nums)<< "\n";
    return 0;
}
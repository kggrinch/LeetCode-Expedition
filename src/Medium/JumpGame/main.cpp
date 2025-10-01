#include <iostream>
#include <vector>

// Recursive Brute Force Approach
// Time Complexity: O(2^n)
// Space Complexity:
bool canJump_recursion(std::vector<int>& nums)
{
    int target = nums.size() - 1;
    auto dfs = [&](int i, auto& dfs) -> bool
    {
        int distance = target - i;
        if (nums[i] >= distance) return true;
        for (int j = i + 1; j <= i + nums[i]; j++)
        {
            if (dfs(j, dfs)) return true;
        }
        return false;
    };

    return dfs(0, dfs);
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
    std::vector<int> nums = {3,0,8,2,0,0,1};
    std::cout << canJump_recursion(nums) << "\n";
    std::cout << canJump_greedy(nums)<< "\n";
    return 0;
}
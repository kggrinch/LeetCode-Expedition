#include <iostream>
#include <unordered_map>
#include <vector>


// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(n)
int rob_recursion(const std::vector<int>& nums)
{
    auto dfs = [&](const std::vector<int>& nums, int i, auto& dfs) -> int
    {
        if (i >= nums.size()) return 0;

        int first_option = dfs(nums, i + 1, dfs);
        int second_option = nums[i] + dfs(nums, i + 2, dfs);
        return first_option >= second_option ? first_option : second_option;
    };

    return dfs(nums, 0, dfs);
}

// DP - Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)
int rob_memoization(const std::vector<int>& nums)
{
    int n = nums.size();
    std::vector<int> cache(n, -1);

    auto rob = [&](const std::vector<int>& nums, const int& i, auto& rob) -> int
    {
        if(i >= n) return 0;
        if(cache[i] != -1) return cache[i];

        cache[i] = std::max(rob(nums, i + 1, rob), nums[i] + rob(nums, i + 2, rob));
        return cache[i];
    };

    return rob(nums, 0, rob);
}

// DP - Tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)
int rob_tabulation(const std::vector<int>& nums)
{
    // If empty return 0
    if(nums.empty()) return 0;

    //If only one value return that value
    int n = nums.size();
    if(n == 1) return nums[0];

    std::vector<int> cache(n);
    cache[0] = nums[0];
    cache[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        cache[i] = std::max(cache[i - 1], nums[i] + cache[i - 2]);
    }

    return cache[n - 1];
}

// DP - Tabulation Optimized (no extra memory space)
// Time Complexity: O(n)
// Space Complexity: O(1)
int rob_tabulation_optimized(const std::vector<int>& nums)
{
    // If empty return 0
    if(nums.empty()) return 0;

    //If only one value return that value
    int n = nums.size();
    if(n == 1) return nums[0];

    int rob1 = nums[0];
    int rob2 = std::max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int temp = rob2;
        rob2 = std::max(rob2, nums[i] + rob1);
        rob1 = temp;
    }

    return rob2;
}

int main()
{
    std::vector<int> nums = {2,7,9,3,1};
    std::cout << rob_recursion(nums) << std::endl;
    std::cout << rob_memoization(nums) << std::endl;
    std::cout << rob_tabulation(nums) << std::endl;
    std::cout << rob_tabulation_optimized(nums) << std::endl;
    return 0;
}

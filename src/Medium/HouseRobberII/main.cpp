#include <iostream>
#include <vector>

// Solution: Since the first and last indexes are adjacent to each other we need to spit the array into two subarrays
//           one without the first index, and the other without the last index. Then we pass in both sub arrays into a
//           House robber 1 solution helper and return the largest value out of the result of passing in two sub arrays into the house robber 1 solution.


// Recursive Solution (Intuitive Approach)
// Time Complexity: O(n)
// Space Complexity: O(n)
int rob_recursive(const std::vector<int>& nums)
{
    if (nums.empty()) return 0;
    if (nums.size() <= 1) return nums[0];

    // Regular House Robber 1 Solution
    auto dfs = [&](const std::vector<int>& nums, int i, auto& dfs) -> int
    {
        if (i >= nums.size()) return 0;

        return std::max(dfs(nums, i + 1, dfs), nums[i] + dfs(nums, i + 2, dfs));
    };

    std::vector<int> sub_array1(nums.begin(), nums.end() - 1); // sub array of nums without the last index
    std::vector<int> sub_array2(nums.begin() + 1, nums.end()); // sub array of nums without the first index
    return std::max(dfs(sub_array1, 0, dfs), dfs(sub_array2, 0, dfs));
}

// Recursive Solution (optimized memory approach)
// Time Complexity: O(n)
// Space Complexity: O(n)
int rob_recursive_optimized(const std::vector<int>& nums)
{
    // Solution: Same approach as the intuitive way except that we use a flag to mark whether the first house was robbed.
    //           If the first house ever is robbed we change the state of the boolean to reflect this and if ever the state
    //           says that the first house was robbed, and we try to rob the last house we will return a 0.

    if (nums.empty()) return 0;
    if (nums.size() <= 1) return nums[0];

    // Regular House Robber 1 Solution
    auto dfs = [&](const std::vector<int>& nums, int i, bool first_house_used, auto& dfs) -> int
    {
        // If i is out of bounds or if first house used and i is at the last house return 0
        if (i >= nums.size() || (first_house_used && i == nums.size() - 1)) return 0;

        return std::max(dfs(nums, i + 1, first_house_used, dfs), nums[i] + dfs(nums, i + 2, first_house_used || i == 0, dfs));
    };

    return std::max(dfs(nums, 0, true, dfs), dfs(nums, 1, false, dfs));
}

// Memoization Solution
// Time Complexity: O(n)
// Space Complexity: O(n)
int rob_memoization(const std::vector<int>& nums)
{
    // Solution: Here we use a 2D array to represent two caches for the two subarrays. If flag is true we indicate
    // If flag is true we indicate that the first house is robbed [1][value] - first house robbed subarray cache
    // If flag is false we indicate that the last house is robbed [0][value] - last house robbed subarray cache

    // Here the first vector represents the second subarray cache and the second vector represents the first subarray cache.
    // [0][value] = subarray1 | [1][value] = subarray2
    std::vector<std::vector<int>> cache(2, std::vector<int>(nums.size(), -1));

    auto dfs = [&](const std::vector<int>& nums, int i, bool flag, auto& dfs) -> int
    {
        // If i is out of bounds or if first house used and i is at the last house return 0
        if (i >= nums.size() || (flag && i == nums.size() - 1)) return 0;
        if (cache[flag][i] != -1) return cache[flag][i];

        cache[flag][i] = std::max(dfs(nums, i + 1, flag, dfs), nums[i] + dfs(nums, i + 2, flag || i == 0, dfs));
        return cache[flag][i];
    };

    return std::max(dfs(nums, 0, true, dfs), dfs(nums, 1, false, dfs));
}

// Tabulation Solution
// Time Complexity: O(n)
// Space Complexity: O(n)
int rob_tabulation(std::vector<int>& nums)
{
    if (nums.size() < 1) return 0;
    if (nums.size() == 1) return nums[0];

    auto house_robber1 = [&](const std::vector<int>& subarray, const int& i, auto& house_robber1) -> int
    {
        const int n = subarray.size();

        if (nums.size() < 1) return 0;
        if (nums.size() == 1) return nums[0];

        std::vector<int> cache(n, -1);

        cache[0] = subarray[0];
        cache[1] = std::max(cache[0], subarray[1]);

        for (int i = 2; i < subarray.size(); ++i)
        {
            cache[i] = std::max(cache[i - 1], subarray[i] + cache[i - 2]);
        }
        return cache[n - 1];
    };
    std::vector<int> subarray1(nums.begin(), nums.end() - 1), subarray2(nums.begin() + 1, nums.end());
    return std::max(house_robber1(subarray1, 0,house_robber1), house_robber1(subarray2, 0,house_robber1));
}

// Tabulation Solution Memory Optimized
// Time Complexity: O(n)
// Space Complexity: O(1)
int rob_tabulation_optimized(const std::vector<int>& nums)
{
    if (nums.size() < 1) return 0;
    if (nums.size() == 1) return nums[0];

    auto house_robber1 = [&](const std::vector<int>& subarray, const int& i, auto& house_robber1) -> int
    {
        if (subarray.size() < 1) return 0;
        if (subarray.size() == 1) return subarray[0];

        int rob1 = subarray[0];
        int rob2 = std::max(rob1, subarray[1]);

        for (int i = 2; i < subarray.size(); ++i)
        {
            int temp = rob2;
            rob2 = std::max(rob2, subarray[i] + rob1);
            rob1 = temp;
        }
        return rob2;
    };
    std::vector<int> subarray1(nums.begin(), nums.end() - 1), subarray2(nums.begin() + 1, nums.end());
    return std::max(house_robber1(subarray1, 0,house_robber1), house_robber1(subarray2, 0,house_robber1));
}


int main()
{
    std::vector<int> nums = {0, 0};
    std::cout << rob_recursive(nums) << "\n";
    std::cout << rob_recursive_optimized(nums) << "\n";
    std::cout << rob_memoization(nums) << "\n";
    std::cout << rob_tabulation(nums) << "\n";
    std::cout << rob_tabulation_optimized(nums) << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <set>

// Time Complexity: O(2^t/m) t = target and m = minimum value in nums
// 2^(t/m) - because we make two recursive calls at each subset.
// (t/m) - because in worse case the depth of the recursive call is the repeated amount of calls of the smallest value in nums until we reach target or in other words
// target / min. ex: t = 10, min = 2 so 10/2 = 5 is the worst case depth of the recursive tree
// Space Complexity: O(2^t/m) t = target and m = minimum value in nums
std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target)
{

    std::vector<std::vector<int>> result;
    auto dfs = [&](int i, std::vector<int> cur, int total, auto& dfs) -> void
    {
        // If total equals the target we found a combination add it to result and return (backtrack)
        if(total == target)
        {
            result.push_back(cur);
            return;
        }
        // If index is past the list or total is greater than target then return (backtrack)
        if(i >= nums.size() || total > target)
        {
            return;
        }

        cur.push_back(nums[i]);
        dfs(i, cur, total + nums[i], dfs);
        cur.pop_back();
        dfs(i + 1, cur, total, dfs);
    };
    std::vector<int> cur;
    dfs(0, cur, 0, dfs);
    return result;
}

int main()
{
    int target = 16;
    std::vector<int> nums = {3,4,5};
    std::vector<std::vector<int>> result = combinationSum(nums, target);
    return 0;
}

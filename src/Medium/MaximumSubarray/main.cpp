#include <iostream>
#include <vector>

// This problem can also be solved using dynamic programming and with divide and conquer algorithms

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxSubArray(std::vector<int>& nums)
{
    if (nums.size() == 1) return nums[0];
    int current_sum{};
    int greatest{nums[0]};
    for (int n : nums)
    {
        if (current_sum < 0) current_sum = 0;
        current_sum += n;
        if (current_sum > greatest) greatest = current_sum;
    }
    return greatest;
}

int main()
{
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << maxSubArray(nums) << "\n";
    return 0;
}
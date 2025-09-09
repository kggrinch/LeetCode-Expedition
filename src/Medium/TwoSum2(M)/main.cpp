#include <iostream>
#include <vector>
#include <unordered_map>

// Time complexity: O(n)
// Space complexity: O(n)
std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    std::unordered_map<int, int> locate;
    for(int i = 0; i < numbers.size(); i++)
    {
        int diff = target - numbers[i];
        if(locate.count(diff) == 1)
        {
            return {locate[diff], i + 1};
        }
        locate.insert({numbers[i], i + 1});
    }
    return {};
}

// Optimized Solution: Two pointer solution
// Time Complexity: O(n)
// Space Complexity: O(1)
std::vector<int> twoSum2(std::vector<int>& numbers, int target)
{
    // Problem:
    // 1. Return the indexes that are indexed+1 with the elements in the array that sum up to the target
    // 2. array is in sorted order
    // 3. return a list of the two indexes

    // Solution:
    // 1. Keep a pointer to the first index and a pointer to the second index.
    //    calculate the sum of the elements at those indexes.
    //    If the sum is greater than the target then decrement the last index
    //    If the sum is less than the target then increment the first index
    //    If the sum is the result then return the two indexes
    //    This works because the array is sorted, so we know that if the result is greater than we need to move
    //    and compare elements that are more toward the beginning of the array. Similarly, if the result is less than
    //    we need to compare element that are more toward the end of the array.

    int first{};
    int last = numbers.size() - 1;
    while(first < last)
    {
        int result = numbers[first] + numbers[last];
        if(result == target) return {first + 1, last + 1};
        else if(result > target) last--;
        else first++;
    }
    return {};

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> res = twoSum2(nums, target);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

// Backtracking problem example
// []           - (empty set is always a subset)
// [1]
// [1, 2]
// [1, 2, 2]
// [1, 2]       - (the second 2 is backtracked)
// [1]          - (the first 2 is backtracked)
// [2]
// [2, 2]
// [2]          - (the second 2 is backtracked)

// Time Complexity: O(2^n * n) - n = number of elements in the past in list | 2^n - number of subsets for n | * n = copying current list into result each time
// Space Complexity: O(2^n * n) - n worse case space for current * number of subsets
std::vector<std::vector<int>> subsetWithDup(std::vector<int> nums)
{
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    std::sort(nums.begin(), nums.end()); // sort so dups are adjacent | nlogn

    auto backtrack = [&](int start, std::vector<int>& current, auto& backtrack) -> void
    {
        // 4. end point. Every recursive call is a valid subset
        result.push_back(current); // creates a copy each time of current n

        // Export further options
        // Iterate over nums from the start position
        for(int i = start; i < nums.size(); i++)
        {
            // 2. choose If duplicates skip
            if(i > start && nums[i] == nums[i-1]) continue;

            // 2. include nums[i] in current subset
            current.push_back(nums[i]);
            // 3. Move forward with the next option
            backtrack(i + 1, current, backtrack);
            // 5. go back to the last choice and try a different way
            current.pop_back();
        }
    };

    // 1. Start at the front with no options chosen
    backtrack(0, current, backtrack);
    return result;
}

// Time Complexity: O(2^n * n) - number of subsets * worse case copy traversal during result.push(current)
// Space Complexity: O(2^n * n) - number of subsets * worse case store the copy of worse case n current elements
// Space Complexity Expanded: O( (2^n * n) + 2n )
// 2^n * n = storing all subsets in result
// n = max size of current vector
// n = max recursive depth
std::vector<std::vector<int>> subsetWithoutDup(std::vector<int> nums)
{
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    auto backtracking = [&](int start, std::vector<int>& current, auto& backtracking) -> void
    {
        result.push_back(current);
        for(int i = start; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            backtracking(i + 1, current, backtracking);
            current.pop_back();
        }
    };
    backtracking(0, current, backtracking);
    return result;
}

int main()
{
    // Backtracking algorithm - refers to the technique of going through all possible configurations in search of a solution

    // Steps to backtracking algorithm
    // 1. Start - begin with no options chosen.
    // 2. Choose - chose whether you want to use the current option or skip it.
    // 3. Move Forward - Consider the next one. If you skip move to the next number but don't add the current one.
    // 4. End point - consider all numbers. Avoid making the same group again.
    // 5. Go back - go back to the last choice and try a different way. Remove the last number used.

    // Example Problem.
    // Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
    // The solution must not contain duplicates subsets. Return the solution in any order.
    // summarize: given a list of numbers return subsets of all unique combinations using the numbers in the list.
    // e.g.
    // Input: nums = [1, 2, 2]
    // Output: [ [], [1], [1, 2], [1, 2, 2], [2], [2, 2] ]
    std::vector<int> nums = {1, 2, 2};
    std::vector<int> nums2 = {1, 2, 3};
    std::vector<std::vector<int>> results = subsetWithDup(nums);
    std::vector<std::vector<int>> results2 = subsetWithoutDup(nums2);




    return 0;
}

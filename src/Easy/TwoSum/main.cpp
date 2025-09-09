#include <iostream>
#include <unordered_map>
#include <vector>

// Brute Force
// Time Complexity: O(n)
std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::vector<int> indices;
    bool exit = false;
    for(int i = 0; i < nums.size(); i++)
    {
        if(exit) break;
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                if(i < j)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                }
                else
                {
                    indices.push_back(j);
                    indices.push_back(i);
                }
                exit = true;
                break;
            }
        }
    }
    return indices;
}

// Most optimized solution
// Time Complexity: O(n)
std::vector<int> twoSum2(std::vector<int>& nums, int target)
{
    int size = nums.size();

    // This holds [value, index in list]
    std::unordered_map<int, int> prevMap;

    for(int i = 0; i < size; i++)
    {
        int difference = target - nums[i];

        // Find if a map contains the difference
        if(prevMap.count(difference) == 1)
        {
            // If map has a value that is the difference return its index with the current i
            // This {} is a syntax thing that returns a vector with
            return {prevMap[difference], i};
        }
        // If no difference found then insert current index value and its index in the list
        prevMap.insert({nums[i], i});
    }
    return {};// returns an empty vector

    // If you do return {1, 2, 3, 4}. It will return a vector with {1, 2, 3, 4} this is like an initializer list
    // constructor in the vector class
}



int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum2(nums, target);
    for(int num : result)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

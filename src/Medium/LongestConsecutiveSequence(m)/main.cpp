#include <iostream>
#include <vector>
#include <map>

int longestConsecutive(std::vector<int>& nums)
{
    // Problem:
    // 1. working with an array
    // 2. return int = length of longest consecutive sequence of values in the array
    //    consecutive sequence = 1 2 3 4 5 6 7 8 9 10
    // 3. must be o(n)

    // Ideas:
    // 1. Sort the array and check if the values have a difference of 1 - takes around nlogn to sort
    // 2. insert everything in a set and then take everything out comparing each values difference
    // 3. Use map with a int counter at the first index sequence indicating the sequence length

    // <value, count>
    std::map<int, int> m;
    for(const auto& n : nums) // O(n)
    {
        m[n] = 1;
    }

    int prev{m.begin()->first};
    int original{m.begin()->first};
    for(const auto& [value, count] : m) // O(n)
    {
        if(prev == value) continue;
        if(std::abs(prev - value) > 1)
        {
            prev = value;
            original = prev;
        }
        else
        {
            prev = value;
            m[original]++;
        }
    }

    int res{};
    for(const auto& [value, count] : m) // O(n)
    {
       if(count > res)
       {
           res = count;
       }
    }

    return res;

    // Time Complexity: O(n)
    // Space Complexity: O(n)
}

int main()
{
    std::vector<int> nums = {2,20,4,10,3,4,5}; //
    std::cout << "Longest consecutive sequence: " << longestConsecutive(nums);
    return 0;

    // 9,1,4,7,3,-1,0,5,8,-1,6
    // Consecutive sequence: -1, 0, 1,
    //                        3, 4, 5, 6, 7, 8, 9
}

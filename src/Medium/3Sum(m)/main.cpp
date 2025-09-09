#include <iostream>
#include <vector>
#include <algorithm>

// IP
std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    // Problem
    // 1. Given a vector return elements of set of 3s in the vector that their sum is 0.
    // 2. return a list of the 3 sets so there can be multiple sets that their sum is 0.
    // 3. The list of 3 sets should not contain duplicate sets, which means there might be sets in different order that need to be removed.
    // 4. Can have a vector that does not contain any sets that their sum is 0
    // 4. Returning a vector<vector>


    // Solution
    // 1. Sort the list.
    //    Iterate through the sorted list and save the values at the index if they are negative and if they dont = the previous value
    //    This value will be the first value in the 3sum. Now use the 2Sum two pointer algorithm technique to find the next two values
    //    that all three combined = 0.
    //    After finding the three values that = 0 increment and decrement the two pointers and use a while loop
    //    to increment one of the pointers until it does not = its previous value. Do this to avoid duplicate answers

    std::sort(nums.begin(), nums.end()); // O(n log n)
    std::vector<std::vector<int>> res;

    for(int i = 0; i < nums.size(); ++i) // O(n)
    {
        if(nums[i] > 0) break; // There is no negative numbers therefore you cant get to 0
        if(i > 0 && nums[i] == nums[i - 1]) continue; // If not first value in the array, and it's the same as the previous
                                                      // value then skip this value
        int start = i + 1;
        int end = nums.size() - 1;
        while(start < end) // O((n - i))
        {
            int threeSum = nums[i] + nums[start] + nums[end];
            if(threeSum > 0) end--;
            else if(threeSum < 0) start++;
            else
            {
                res.push_back({nums[i], nums[start], nums[end]});
                // This updates one of the pointer to make sure that the same pointer is not used in case of duplicates
                // Ex: [-2, -2, 1, 0, 2, 2]
                //       l               r - found a solution so increment the poiners by 1
                //           l        r    - now check if the left pointer is the same as the previous - if we don't check then we end up with a duplicate answer
                //              l     r    - now the rest of the while loop up top will check for correct answers
                //
                start++;
                end--;
                while(start < end && nums[start] == nums[start - 1]) // O(1)
                {
                    start++;
                }
            }
        }
    }
        return res;

    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
}


int main()
{
    std::vector<int> nums {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> res = threeSum(nums);

    return 0;
}

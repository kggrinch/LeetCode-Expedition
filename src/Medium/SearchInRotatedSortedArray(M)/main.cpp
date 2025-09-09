#include <iostream>
#include <vector>

int binary_search(std::vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int middle = left + (right - left) / 2;
        if(nums[middle] == target) return middle;
        else if(target > nums[middle]) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}

// Most optimal solution
// Time Complexity: O(log n)
// Space Complexity: O(1)
int search(std::vector<int>& nums, int target)
{
    // Problem - 1. Array is sorted
    //           2. Array is rotated between 1 - n times
    //           3. if array is rotated n times it will be back in correct order
    //           4. Return an int index of where the target is in the array
    //           5. All elements in the array is unique
    //           6. Solution must be in O(log n) times (use binary search)
    //           7. return -1 if target is not in the array

    // Solution - 1. Use a binary search technique where you save one left and right index.
    //            2. Binary search through the array moving the middle index based of conditions of the left most index
    //               a) if the middle value is greater than the left value, then the middle index is in the greater subset
    //                   Moving right from here will reach the greatest value in the array and then past that will reach minimum and the minimum subset
    //                   Moving left from here will traverse all values in between the left and middle indexes
    //               b) if the middle value is less than the left value, then the middle index is in the minimum subset
    //                   Moving right from here will traverse all values in between the right and middle indexes
    //                   Moving left from here will reach the minimum value and then the greatest value and then enter the greater subset

    // 1. Create indexes
    int left = 0;
    int right = nums.size() - 1;

    // If array is in correct order perform normal binary search
    if(nums[left] < nums[right]) return binary_search(nums, target); // O(log(n))

    while(left <= right) // O(log(n))
    {
        int middle = left + (right - left) / 2;

        // Check if target is in the middle, left, or right indexes
        if(nums[middle] == target) return middle;
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;

        // If middle value is greater or equal to the left value
        // The middle index is in the greater subset array
        if(nums[middle] >= nums[left])
        {
            // If target is less then the left most value or target is greater than the middle value move right
            if(target < nums[left] || target > nums[middle]) left = middle + 1;
            else right = middle - 1; // Else target is somewhere in the between the left and middle index move left
        }
        // If middle value is less than the left value then middle index is in the minimum subset array
        else
        {
            // If target is greater than the right value and less than the middle value move left
            if(target > nums[right] || target < nums[middle]) right = middle - 1;
            else left = middle + 1; // Else the target is somewhere in between the right and middle indexes move right
        }
    }
    return -1;

    // Time Complexity: O(log n)
    // Space Complexity: O(1)
}

int main()
{

    std::vector<int> nums = {4,5,6,7,8,1,2,3};
    int target = 8;
    std::cout << search(nums, target)  << "\n";

    return 0;
}

#include <iostream>
#include <vector>

// IP
int findMin(std::vector<int>& nums)
{
    // Problem - Given a sorted array rotated between 1 - n times return the minimum
    //           1. Array is sorted in ascending order
    //           2. Array is rotated in the right direction from 1-n times
    //              a) if rotated n times the array stayed in the same order
    //           3. Every value in the array is unique no duplicates
    //           4. return an integer minimum value in the array

    // Solution - 1. The idea here is to use binary search but in a way to locate the point in the array
    //               where the discrepancy between the values are. Like the point in the array where the sorted aspect breaks due to the rotation
    //               Ex: discrepancy happens at indexes 2 and 3    [3, 4, 5, 0, 1, 2] - one of the indexes contains the min value
    //
    // Steps -    a) Create a left and right index pointers and save the left value as the min value on default.
    //            b) Check if the array is rotated and sorted in correct positions already by checking if the left value is less than the right
    //               If the array is already sorted and correctly position I will refer to this as a correct array.
    //                 If so return the left most value; otherwise continue.
    //            c) Iterate through the array by using the left and right pointers
    //               d) In each iteration check if the indexes are in the correct position creating a correct array
    //                  if so return the min value between the current saved min value or the current left value
    //               e) If the index of the array dont show a correct array then find the middle index.
    //               f) Check if the value in the middle index is greater than the value at the left index. If so
    //                  then the min value is somewhere right of the middle index.
    //               g) If the value in the middle index is less than the left index than the value is somewhere left of the middle index.
    //            h) after the iteration return the min value.


    //            2. Perform binary search on the array offset based on how much it was rotated.
    //               a) find out how much it was offset by
    //               b)

    int min = nums[0]; // Save the min value
    int l = 0;
    int r = nums.size() - 1;
    if(nums[l] < nums[r]) return nums[l]; // If the array is normal return the left most element

    // do <= because there can be cases where there are only two
    // values and the min value is not found due to not doing a further each
    // with only <.
    while(l <= r) // log n
    {
        if(nums[l] < nums[r])
        {
            // If left index is less than right we have found the subset of the array that is sorted
            // in correct order. Therefore, return the left most index or the current min whichever is less.
            return nums[l] < min ? nums[l] : min;
        }
        int m =  l + (r - l) / 2; // Find the middle index
        if(nums[m] <  min) min = nums[m]; // If middle index is less than the min update the min value

        // If the middle value is greater than left value then all the values on the left are
        // a part of the subset that contains the greatest value not the minimum value. Therefore,
        // move to the right.
        if(nums[m] >= nums[l]) l = m + 1;
        // If the middle value is less than the left value than, we are currently at the subset with the minimum value,
        // but we are not at the left most index of that subset. Therefore, move left.
        else r = m - 1;
    }
    return min;

    // Time Complexity: O(log n)
    // Space Complexity: O(1)
}

int main()
{
    std::vector<int> nums = {2, 1};
    std::cout << "Min value: " << findMin(nums);
    return 0;
}

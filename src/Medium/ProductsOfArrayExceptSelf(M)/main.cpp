#include <iostream>
#include <vector>

// Prefix & Suffix solution
//
// Time Complexity: O(n)
// Space Complexity: O(n)
std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    // int n2 = nums.size();
    // std::vector<int> res2(n2);
    // std::vector<int> pre2(n2);
    // std::vector<int> suf2(n2);
    //
    // pre2[0] = nums[0];
    // suf2[n2 - 1] = nums[n2 - 1];
    //
    // // O(n) fill prefix
    // for (int i = 1; i < n2; ++i) {
    //     pre2[i] = pre2[i - 1] * nums[i];
    // }
    //
    // // O(n) fill suffix
    // for (int i = n2 - 2; i >= 0; --i) {
    //     suf2[i] = suf2[i + 1] * nums[i];
    // }
    //
    // // Insert first element with 1 because cannot reach out of bounds suffix
    // res2[0] = 1 * suf2[1];
    // // Fill res up until the last element
    // for (int i = 1; i < n2 - 1; ++i) {
    //     res2[i] = pre2[i - 1] * suf2[i + 1];
    // }
    // // Insert last element with 1 because cannot reach out of bounds prefix
    // res2[n2 - 1] = pre2[n2 - 2] * 1;
    // return res;



    // This is a cleaner code for the top technique.
    // Instead of manually taking care of the 0 and last out of bound indexes, we store them into the array.
    // Therefore, the prefix will hold the 1 at the 0 index, and suffix will hold the 1 at the last index.
    // This makes it so the arrays have the out-of-bounds values within the array and can iterate the array in a way
    // multiply its values with the out-of-bounds indexes.

    // This is a more complicated prefix and suffix that does an offset of 1 so each fix is happened at an offset index of 1.
    // This is happening so that you can reach the out of bounds values in the prefixes and suffixes which will always be 1.
    int n = nums.size();
    std::vector<int> res(n);
    std::vector<int> pref(n);
    std::vector<int> suff(n);

    pref[0] = 1;
    suff[n - 1] = 1;
    for (int i = 1; i < n; i++) {
        pref[i] = nums[i - 1] * pref[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = nums[i + 1] * suff[i + 1];
    }
    for (int i = 0; i < n; i++) {
        res[i] = pref[i] * suff[i];
    }
    return res;
}

// Prefix and suffix Most optimal solution
// Explanation: This solution is the same approach as the prefix and suffix solution but instead of using two arrays
//              to hold the prefix and suffix we will use one single result array to calculate the prefix and suffix in
//              that array. This saves us some space.
// Time Complexity: O(n)
// Space Complexity: O(1)
std::vector<int> productExceptSelfOptimal(std::vector<int>& nums)
{
    int n = nums.size();
    std::vector<int> res(n, 1);

    // Loop through the prefix way saving the prefix values into the result with a offset of one to get the
    // 1 when at the 0 index
    for(int i = 1; i < n; ++i)
    {
        res[i] = res[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for(int i = n - 1; i >= 0; --i)
    {
        res[i] *= suffix;
        suffix *= nums[i];
    }
    return res;
}


int main()
{
    // Prefix and suffix
    std::vector<int> nums = {1,2,3,4};
    std::vector<int> res = productExceptSelf(nums);
    for(auto r : res)
    {
        std::cout << r << " ";
    }
    std::cout << "\n";

    // prefix and suffix optimal
    std::vector<int> nums2 = {1,2,3,4};
    std::vector<int> res2 = productExceptSelfOptimal(nums2);
    for(auto r : res2)
    {
        std::cout << r << " ";
    }
    std::cout << "\n";


}

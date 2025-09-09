#include <iostream>
#include <vector>

// Brute force approach
// Time complexity: O(nm + n)
// int removeDuplicates(std::vector<int>& nums)
// {
//     std::vector<int> temp;
//     temp.push_back(nums[0]);
//
//     for(int i = 1; i < nums.size(); i++) O(n)
//     {
//         bool dup = false;
//         for(int j = 0; j < temp.size(); j++) O(m)
//         {
//             if(nums[i] == temp[j])
//             {
//                 dup = true;
//             }
//         }
//         if(!dup)
//         {
//             temp.push_back(nums[i]);
//         }
//     }
//
//     int current_it = 0;
//     for(int i = 0; i < temp.size(); i++) O(n)
//     {
//         nums[current_it] = temp[i];
//         current_it++;
//     }
//     return temp.size();
// }


// Optimize solution but uses unnecessary extra memory of another array
// Time complexity: O(not full n) + (not fully n) + o(n) = only non_duplicates + only_duplicates + copy = O(n)
// int removeDuplicates(std::vector<int>& nums)
// {
//     // Create temp to hold non-dup values
//     std::vector<int> temp;
//
//     // for loop to go over the array
//     for(int i = 0; i < nums.size();) // O(n) only non_duplicate values
//     {
//         temp.push_back(nums[i]);// Add item at i to temp since i will always point to a non-duplicate value
//
//         // Count the number of similar items to i
//         int number_of_similar_values = 1;
//         // Check if item is similar to i, and if numbers of similar item index is in range
//         while(i + number_of_similar_values < nums.size() && nums[i] == nums[i + number_of_similar_values]) // O(n) only duplicate values
//         {
//             number_of_similar_values++; // if similar item is found, increment similar number index to check the next item
//         }
//
//         // at the end of the while loop number_of_similar_values index will hold the number of items that are similar to index. Therefore,
//         // update i index to skip all the similar items.
//         i += number_of_similar_values;
//     }
//
//     // place non_duplicate items into original array
//     for(int i = 0; i < temp.size(); i++) // o(n)
//     {
//         nums[i] = temp[i];
//     }
//     return temp.size(); // return new size
// }

// most optimized solution. In place removing
// Time Complexity: O(n) same as similar but with better memory management
int removeDuplicates(std::vector<int>& nums)
{
    // Create index to update original array in place
    int new_index = 0;

    // for loop to go over the array
    for(int i = 0; i < nums.size();)
    {
        // Add item at i to current_index since i will always point to a non-duplicate value
        nums[new_index] = nums[i];
        new_index++;

        // Count the number of similar items to i
        int number_of_similar_values = 1;
        // Check if item is similar to i, and if numbers of similar item index is in range
        while(i + number_of_similar_values < nums.size() && nums[i] == nums[i + number_of_similar_values])
        {
            number_of_similar_values++; // if similar item is found, increment similar number index to check the next item
        }

        // at the end of the while loop number_of_similar_values index will hold the number of items that are similar to the value at index.
        // Therefore, update i index to skip all the similar items.
        i += number_of_similar_values;
    }

    return new_index; // return new size
}




void print_vector(std::vector<int>& vec, int length)
{
    for(int i = 0; i < length; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}



int main()
{
    std::vector<int> vect;

    vect.push_back(1);
    vect.push_back(2);


    print_vector(vect, 1);
    int new_length = removeDuplicates(vect);
    print_vector(vect, new_length);

    return 0;
}

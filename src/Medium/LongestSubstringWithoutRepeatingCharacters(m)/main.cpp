#include <iostream>
#include <unordered_set>

// Sliding Window - IP
// Time Complexity:
// Space Complexity: O(n)
int lengthOfLongestSubstring(std::string s)
{
    // Problem - 1. Given a string find the longest substring without duplicate characters
    //           2. Return an int indicating the longest substring without duplicate characters
    //           3. substring - a string inside the main string

    // Ideas - 1. Use something with the ASCII table
    //         2. Use a set to keep track of duplicate characters and use two pointers

    // Solution - 1. Use sliding window

    std::pmr::unordered_set<char> d_check;
    int l = 0;
    int res{};

    d_check.insert(s[l]);
    for(int r = 0; r < s.length(); ++r)
    {

    }

}

// Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(n)
int lengthOfLongestSubstring2(std::string s)
{
    // Problem - 1. Given a string find the longest substring without duplicate characters
    //           2. Return an int indicating the longest substring without duplicate characters
    //           3. substring - a string inside the main string

    // Ideas - 1. Use something with the ASCII table
    //         2. Use a set to keep track of duplicate characters and use two pointers

    // Solution - 1. Use two pointers with a set.
    //               a) The two pointers will start at the beginning of the string with one at the 0 index and the other at the 1 index
    //               b) use the set to check of duplicates at the current positions of the pointers
    //               c) Insert the two values into the set and check if they are duplicates
    //               d) If the two values are not duplicates then set the longest substring as the distance between the two pointers
    //                  and increment the second pointer.
    //               e) Insert the second pointer into the set and check for duplicates if no duplicate update the longest string
    //               f) keep repeating until you reach a duplicate
    //               g) Once a duplicate it reach clear the set and move the left pointer to the right pointer and increment the right pointer
    //               h) Repeat the longest string steps if a longer substring is found update longest string

    // If string is one character return that character
    if(s.empty()) return 0;
    if(s.length() < 2) return 1;

    std::pmr::unordered_set<char> d_check; // Keeps track of duplicates
    int l = 0;
    int r = 1;
    int res{1}; // Might need to modify default value

    // Check if the two pointers are dups (maybe)
    // if(s[l] == s[r])

    d_check.insert(s[l]); // Insert the left before bc this pointer will only move on specific conditions
    while(r < s.length()) // O(n^2)
    {
        // Check if r value already exists in the set
        if(d_check.count(s[r]) == 1)
        {
            l++;
            r = l + 1;
            d_check.clear();
            d_check.insert(s[l]);
        }
        else
        {
            int len = r - l + 1;     // calculate the substring from r and l
            if(len > res) res = len; // update the longest substring if the substring between r and l is longer
            d_check.insert(s[r]);    // Insert value at r into the set
            r++;                     // Increment r
        }
    }
    return res;
}


int main()
{
    std::string s = "dvdf";
    std::cout << "length of longest sub-string: " << lengthOfLongestSubstring(s) << "\n";

    return 0;
}


// dvedfgjik
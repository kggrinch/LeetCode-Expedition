#include <iostream>
#include <vector>


// IsUnique: Implement an algorithm to determine if a string has all unique characters. What if you
//           cannot use additional data structures?

// Info: unique characters | no additional dsa

// Example: "aejbfjeuy"
// Solution false

// Brute Force:
// 1. Loop through each element twice O(n^2)
// 2. Set: T(n) = O(n) | S(n) = O(n)
// 3. Sort: T(n) = O(n log n)

// Best implementation:
// 1. Vector with set alphabetical elements | T(n) = O(n) | S(n) = O(26) = O(1)

// Time Complexity: O(n)/O(1) - O(1) because loop will never go beyond O(128)
// Space Complexity: O(1) = O(128)
bool isUnique(std::string s)
{
    // Cannot have string with more than 128 char and no duplicates
    if (s.length() > 128) return false;

    std::vector<bool> unique(128, false);
    for (const char& c : s)
    {
        unsigned int val = c;
        if (unique[val]) return false;
        unique[val] = true;
    }
    return true;
}

bool compare(const bool& output, const bool& expected)
{
    return output == expected;
}

void tests()
{

    // Concept
    std::string s1 = "abcdefghi";
    std::string s2 = "abcdefghia";

    // non_standard
    std::string s3 = "123";
    std::string s4 = "";
    std::string s5 = ">";

    // hotspots
    std::string s6 = "abcdefghi1";

    // Special cases
    std::string s7 = "abc d";
    std::string s8 = "a";

    std::string test = "";
    bool pass = true;

    if (!compare(isUnique(s1), true)) {std::cout << "s1 Failed!!!\n"; pass = false;}
    if (!compare(isUnique(s2), false)) {std::cout << "s2 Failed!!!\n"; pass = false;}
    if (!compare(isUnique(s3), true)) {std::cout << "s3 Failed!!!\n"; pass = false;}
    if (!compare(isUnique(s4), true)) {std::cout << "s4 Failed!!!\n"; pass = false;}
    if (!compare(isUnique(s5), true)) {std::cout << "s5 Failed!!!\n"; pass = false;}
    if (!compare(isUnique(s6), true)) {std::cout << "s6 Failed!!!\n"; pass = false;}
    if (!compare(isUnique(s7), true)) {std::cout << "s7 Failed!!!\n"; pass = false;}
    if (!compare(isUnique(s8), true)) {std::cout << "s8 Failed!!!\n"; pass = false;}

    if (pass) std::cout << "All Tests Passed!!!\n";
}

int main()
{
    tests();
    return 0;
}
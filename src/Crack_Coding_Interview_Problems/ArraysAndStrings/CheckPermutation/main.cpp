#include <iostream>
#include <vector>

// CheckPermutation: Given two strings, write a method to decide if one is a permutation of the other.

// Permutation definition: A string that is the same no matter the order of characters.

// Info: two strings | return type bool | permutation = continues

// Examples:
// 1. s1 = "abc" | s2 = "bac" | true
// 2. s1 = "eet" | s2 = "teet" | false
// 3. s1 = "eet" | s2 = "abcdefett" | false

// Approaches:
// 1. Sort both strings compare directly | T = O(s1 log s1 + s2 log s2) | S = O(1)
// 2. Frequency hashmap | T = O(s1 + s2) | S = O(s1 + s2)
// 3. Frequency vector | T(s1 + s2) | S = O(1)

// Time Complexity: O(s1 + s2)
// Space Complexity: O(1)
bool CheckPermutation(const std::string& s1, const std::string& s2)
{
    if (s1.size() != s2.size()) return false;

    std::vector<int> s1_freq(128, 0);
    for (const char& c : s1)
    {
        unsigned int val = c;
        s1_freq[val]++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        unsigned int val = s2[i];
        s1_freq[val]--;
        if (s1_freq[val] < 0) return false;
    }
    return true;
}

bool compare(const bool& outcome, const bool& expected)
{
    return outcome == expected;
}

void test()
{
    std::string s1 = "abc";
    std::string s2 = "bca";

    std::string s3 = "eet";
    std::string s4 = "teet";

    std::string s5 = "eet";
    std::string s6 = "abcdefeet";

    std::string s7 = "a";
    std::string s8 = "abc";

    std::string s9 = "a";
    std::string s10 = "a";

    if (!compare(CheckPermutation(s1, s2), true)) std::cout << "s1/s2 Failed\n";
    else if (!compare(CheckPermutation(s3, s4), false)) std::cout << "s3/s4 Failed\n";
    else if (!compare(CheckPermutation(s5, s6), false)) std::cout << "s5/s6 Failed\n";
    else if (!compare(CheckPermutation(s7, s8), false)) std::cout << "s7/s8 Failed\n";
    else if (!compare(CheckPermutation(s9, s10), true)) std::cout << "s9/s10 Failed\n";
    else {std::cout << "All Tests Passed!!\n";}

}






int main()
{
    test();
    return 0;
}
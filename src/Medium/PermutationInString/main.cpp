#include <iostream>
#include <vector>

// CheckPermutation: Given two strings, write a method to decide if one is a permutation of the other.

// Info: two strings | return type bool | premuation = continues

// Examples:
// 1. s1 = "abc" | s2 = "skejjbcad" | true
// 2. s1 = "eet" | s2 = "abcdef" | false
// 3. s1 = "eet" | s2 = "abcdefett"

// Approaches:
// 1. Loop for first char. check surrouding for the other characters | T(n) = O(s1 * s2)
// 2. hashmap | T = O(s1 * s2) | S = O(s1)
// 3. vector | T = O(s1 * s2) | S = O(1)
// 4. vector optimized | T = | S = O(1) | dont fill every fail but bring back decremented increments



// O(s1)
void fill_increments(const std::string& s1, std::vector<int>& increments)
{
    for (const char& c : s1)
    {
        unsigned int val = c;
        increments[val]++;
    }
}

// Time Complexity: O(s2 * s1)
// Space Complexity: O(1)
bool CheckPermutation(const std::string& s1, const std::string& s2)
{
    if (s1 == s2) return true;

    int s1_length = s1.size();
    std::vector<int> increments(128, 0);
    fill_increments(s1, increments); // O(s1)
    for (int i = 0; i < s2.size(); i++)
    {
        unsigned int val = s2[i];
        if (increments[val] != 0)
        {
            s1_length--;
            increments[val]--;
            if (s1_length == 0) return true; // edge case handling: first permutation char on string
            for (int j = i + 1; j < s2.size(); j++)
            {
                unsigned int val = s2[j];
                if (increments[val] == 0)
                {
                    s1_length = s1.size();
                    fill_increments(s1, increments); // O(s1)
                    i = j;
                    break;
                }
                s1_length--;
                increments[val]--;
                if (s1_length == 0) return true; // edge case handling: reaches last permutation char on last string char
            }
        }
    }
    return false;
}

// Time Complexity: O(s2 + s1)
// Space Complexity: O(s1)
bool CheckPermutation_optimal(const std::string& s1, const std::string& s2)
{
    int s1_length = s1.size();
    std::vector<int> increments(128, 0);
    fill_increments(s1, increments); // O(s1)
    for (int i = 0; i < s2.size(); i++) // O(s2)
    {
        unsigned int val = s2[i];
        if (increments[val] != 0)
        {
            s1_length--;
            increments[val]--;
            if (s1_length == 0) return true; // edge case handling: first permutation char on string
            std::vector<unsigned int> used_values;
            used_values.push_back(val);
            for (int j = i + 1; j < s2.size(); j++)
            {
                unsigned int val = s2[j];
                if (increments[val] == 0)
                {
                    s1_length = s1.size();
                    for (unsigned int value : used_values) increments[value]++; // O(s1)
                    i = j; // makes loop linear
                    break;
                }
                s1_length--;
                increments[val]--;
                used_values.push_back(val);
                if (s1_length == 0) return true; // edge case handling: reaches last permutation char on last string char
            }
        }
    }
    return false;
}



bool compare(const bool& outcome, const bool& expected)
{
    return outcome == expected;
}

void test()
{
    std::string s1 = "abc";
    std::string s2 = "skejjbcad";

    std::string s3 = "eet";
    std::string s4 = "abcdef";

    std::string s5 = "eet";
    std::string s6 = "abcdefeet";

    std::string s7 = "a";
    std::string s8 = "abc";

    std::string s9 = "aa";
    std::string s10 = "aab";

    if (!compare(CheckPermutation_optimal(s1, s2), true)) std::cout << "s1/s2 Failed\n";
    else if (!compare(CheckPermutation_optimal(s3, s4), false)) std::cout << "s3/s4 Failed\n";
    else if (!compare(CheckPermutation_optimal(s5, s6), true)) std::cout << "s5/s6 Failed\n";
    else if (!compare(CheckPermutation_optimal(s7, s8), true)) std::cout << "s7/s8 Failed\n";
    else if (!compare(CheckPermutation_optimal(s9, s10), true)) std::cout << "s9/s10 Failed\n";
    else {std::cout << "All Tests Passed!!\n";}

}

int main()
{
    test();
    return 0;
}
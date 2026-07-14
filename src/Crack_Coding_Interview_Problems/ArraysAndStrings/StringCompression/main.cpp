#include <iostream>

// Problem -    Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa
//              would become a2b1c5a3. If the "compressed" string would not become smaller than the original string,
//              your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).

// Important notes:
// 1. no inplace operations
// 2. compressed string > original = return original
// 3. uppercase and lowercase (a-z)

// Questions:
// 1. is it continuous letters (assume yes)
// 2.

// Examples
// 1. aabcccccaaa -> a2b1c5a3
// 2. aa -> a2 -> aa
// 3. aaabbcc -> a3b2c2
// 4. abc ->a1b1c1 -> abc

// Solutions
// 1. loop save count change and compare original size | O(n) | S(1)
// 2. hashmap char counter | O(n) | S(n)

// Optimal Solution
//

bool compressionNeeded(const std::string& s)
{
    int orig_size = s.size();
    int new_char = 1;
    char cur_char = s[0];
    for (char c : s)
    {
        if (c != cur_char)
        {
            new_char++;
            cur_char = c;
        }
    }

    if (orig_size <= (new_char * 2)) return false;
    return true;
}

std::string stringCompression(std::string& s)
{
    // Check if compression need
    if (!compressionNeeded(s)) return s;

    std::string new_s;
    int orig_size = s.size();
    int char_count = 1;
    char cur_char = s[0];
    int cur_char_index = 0;

    for (int i = 1; i < orig_size; i++)
    {
        if (cur_char != s[i])
        {
            // Save cur char count and new replacement
            int cur_char_count = char_count;
            std::string replacement = cur_char + std::to_string(cur_char_count);

            // change to new letter before string modifications
            cur_char = s[i];
            char_count = 1; // update this to 0 and redu th eindexing

            // deal with cur letter attributes (index at new letter)
            new_s += replacement;
            // s.replace(cur_char_index, cur_char_count, replacement);

            // update indexing
            cur_char_index = i; // next cur char is at the next index position after update
        }
        else
        {
            char_count++;
        }
    }

    return new_s;
}

bool compare(const std::string& expected, const std::string& outcome)
{
    return expected == outcome;
}

bool runTest(int test_num, const std::string& expected, const std::string& outcome)
{
    if (!compare(expected, outcome))
    {
        std::cout << "Test " << test_num << " Failed | Expected: " << expected << " Outcome: " << outcome << "\n";
        return false;
    }
    std::cout << "Test " << test_num << " Passed\n";
    return true;
}

bool testSimple()
{
    // 1. aabcccccaaa -> a2b1c5a3
    // 2. aa -> a2 -> aa
    // 3. aaabbcc -> a3b2c2
    // 4. abc ->a1b1c1 -> abc
    std::string s1 = "aabcccccaaa";
    if (!runTest(0, "a2b1c5a3", stringCompression(s1))) return false;
    std::string s2 = "aa";
    if (!runTest(1, "aa", stringCompression(s2))) return false;
    std::string s3 = "aaabbcc";
    if (!runTest(2, "a3b2c2", stringCompression(s3))) return false;
    std::string s4 = "abc";
    if (!runTest(3, "abc", stringCompression(s4))) return false;
    return true;
}

void runTestSuite()
{
    testSimple();
}




int main()
{
    runTestSuite();
    return 0;
}
#include <cmath>
#include <iostream>

// Problem: There are three types of edits that can be performed on strings: insert a character,
//          remove a character, or replace a character. Given two strings, write a function to check if they are
//          one edit (or zero edits) away.

// Example:
// 1. pale, ple -> true
// 2. pales, pale -> true
// 3. pale, bale -> true
// 4. pale, bake -> false
// 5. apple, ale -> false
// 6. pale, pales -> true
// 7. pales pa

// Questions:
// 1. Is it all lowercase characters?

// Solutions:
// 1, Check each char at each step (two pointer) | N(n + m) | S(1)
// 2. char hash counter |


bool OneAway(std::string a, std::string b)
{
    // if same string return true
    // one empty the other length > 1 or size difference greater than 2
    if (a == b) return true;
    if ((std::abs(static_cast<int>(a.length()) - static_cast<int>(b.length())) > 2) ||  (a == "" && b.length() > 1) || (b == "" && a.length() > 1)) return false;

    int error_counter{};
    // int a_index{};
    // int b_index{};
    int longest_string = a.length() > b.length() ? a.length() : b.length();

    // a longest string
    if (longest_string == a.length())
    {
        int b_index{};
        for (int a_index = 0; a_index < longest_string; a_index++)
        {
            if (error_counter >= 2) return false;
            if (a[a_index] == b[b_index]) {b_index++; continue;}

            error_counter++;
            a_index++;
            b_index++;
        }
    }
    else
    {
        int a_index{};
        for (int b_index = 0; b_index < longest_string; b_index++)
        {
            if (error_counter >= 2) return false;
            if (a[a_index] == b[b_index]) {b_index++; continue;}

            error_counter++;
            b_index++;
            a_index++;
        }
    }
    if (error_counter >= 2) return false;
    return true;
}


// Optimized solution helper function
bool oneEditReplace(std::string s1, std::string s2)
{
    bool foundDifference = false;
    for (int i= 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            if (foundDifference) return false;
            foundDifference = true;
        }
    }
    return true;
}

bool oneEditinsert(std::string s1, std::string s2)
{
    int index1 = 0;
    int index2 = 0;
    while (index2 < s2.length() && index2 < s1.length())
    {
        if (s1[index1] != s2[index2])
        {
            if (index1 != index2) return false;
            index2++;
        }
        else
        {
            index1++;
            index2++;
        }
    }
    return true;
}


// Optimized Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
bool OneAwayOptimized(std::string first, std::string second)
{
    if (first.length() == second.length()) {
        return oneEditReplace(first, second);
    } else if (first.length()+ 1 == second.length()) {
        return oneEditinsert(first, second);
    } else if (first.length() - 1 == second.length()) {
        return oneEditinsert(second, first);
    }
    return false;

}


bool compare(const bool& output, const bool& expected)
{
    return output == expected;
}

bool runTest(const int& testNum, const bool& output, const bool& expected)
{
    if (compare(output, expected))
    {
        std::cout << "Test " << testNum << " Passed\n";
        return true;
    }
    std::cout << "Test " << testNum << " Failed (Expected: " << expected << " Output: " << output << "\n";
    return false;
}

bool runSimple()
{
    if (!runTest(1, OneAwayOptimized("pale", "ple"), true)) return false;
    if (!runTest(2, OneAwayOptimized("pales", "pale"), true)) return false;
    if (!runTest(3, OneAwayOptimized("pale", "bale"), true)) return false;
    if (!runTest(4, OneAwayOptimized("pale", "bake"), false)) return false;
    if (!runTest(5, OneAwayOptimized("apple", "ale"), false)) return false;
    if (!runTest(6, OneAwayOptimized("pale", "pales"), true)) return false;
    if (!runTest(7, OneAwayOptimized("pales", "pa"), false)) return false;
}

void runTestSuite()
{
    if (!runSimple()) return;
}



int main()
{
    runTestSuite();
    return 0;
}
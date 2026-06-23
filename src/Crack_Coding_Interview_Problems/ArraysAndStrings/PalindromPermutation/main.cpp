#include <iostream>
#include <vector>

// Problem: Given a string, write a function to check if it is a permutation of a palindrome.
//          A palindrome is a word or phrase that is the same forwards and backwards. A permutation
//          is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

// Example 1:   Input = Tact Coa
//              Output = True (permutations: "taco cat", "atco eta", etc.)

// Example 2:   Input = ppqretrs
//              Ouput - False = (no permutations that are palindromes)

// Approach
// 1. Keep a char count if all char counts are even then true | T(n) = O(n) | S(n) = O(1)


// T(n) = O(n)
// S(n) = O(1)
bool isPalindromePermutation(std::string s)
{
    std::vector<int> charCount(26, 0);

    // Remove all spaces
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            s.erase(i, 1);
        }
    }

    // char count
    for (const char& c : s)
    {
        if (isdigit(c)) continue; // if not numeric value proceed otherwise skip numeric value
        int index = tolower(c) - 'a'; // make c lowercase then insert in index
        charCount[index]++;
    }

    // if s is odd 1 odd char allowed
    if (s.length() % 2 != 0)
    {
        bool one_odd{};

        // Check if char has any odds
        for(const int& count : charCount)
        {
            if (count % 2 != 0)
            {
                if (one_odd) return false;
                one_odd = true;
            }
        }
    }
    else // else s is even no odd char allowed
    {
        // Check if char has any odds
        for(const int& count : charCount)
        {
            if (count % 2 != 0) return false;
        }
    }

    return true;
}


// Testing
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

    std::cout << "Test " << testNum << " Failed (Expected: " << expected << " Output: " << output << ")\n";
    return false;
}

bool test_light()
{
    if (!runTest(0, isPalindromePermutation("bbb"), true)) return false;
    if (!runTest(1, isPalindromePermutation("abcba"), true)) return false;
    if (!runTest(2, isPalindromePermutation("abc"), false)) return false;
    if (!runTest(3, isPalindromePermutation("abcdabcd"), true)) return false;
    if (!runTest(4, isPalindromePermutation("abc bad"), false)) return false;
    return true;
}

bool test_long()
{
    if (!runTest(5, isPalindromePermutation("abcabcabcabc"), true)) return false;
    if (!runTest(6, isPalindromePermutation("popcilce"), false)) return false;
    if (!runTest(7, isPalindromePermutation("tacoca t"), true)) return false;
    return true;
}

bool test_edge()
{
    if (!runTest(8, isPalindromePermutation("a"), true)) return false;
    if (!runTest(10, isPalindromePermutation(""), true)) return false;
    if (!runTest(11, isPalindromePermutation("    aa      "), true)) return false;
    if (!runTest(12, isPalindromePermutation("123"), true)) return false;
    return true;
}


void runTestSuite()
{
    if (!test_light()) return;
    if (!test_long()) return;
    if (!test_edge()) return;
}



int main()
{
    std::string s = "Tact Coa";
    std::cout << isPalindromePermutation(s) << "\n";

    runTestSuite();
    return 0;
}
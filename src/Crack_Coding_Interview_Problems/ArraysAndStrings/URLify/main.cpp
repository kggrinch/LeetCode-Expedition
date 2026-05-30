#include <iostream>

// Problem: Write a method to replace all spaces in a string with '%20'. You may assume that the string
//          has sufficient space at the end to hold the additional characters, and that you are given the "true"
//          length of the string. (Note: If implementing in Java, please use a character array so that you can
//          perform this operation in place.)

// Example: Input:  "Mr John Smith    ", 13
//          Output: ""Mr%20John%20Smith

// Example 2: Input: "  Hello Partner  ", 13
//            Output: "Hello%20Partner"

// Approach
// 1. Find space, count distance first char __ last char, replace function | T(n) = O(n) | S(n) = O(1)
// 2.

// T(n) = O(n)
// S(n) = O(1)
void trim(std::string& s)
{
    int start = s.find_first_not_of(" \t\n\r\f\v");
    int end = s.find_last_not_of(" \t\n\r\f\v");
    s = s.substr(start, end - start + 1);
}

// T(n) = O(n)
// S(n) = O(1)
void URLify(std::string& s, const int& string_length)
{
    trim(s); // remove beginning and ending white space
    std::string repl_str = "%20";
    int pos{}; // pos
    int count{};
    for (int i = 0; i < string_length; i++)
    {
        if (s[i] == ' ')
        {
            if (count == 0) pos = i;
            count++;
        }
        else
        {
            if (pos != 0) s.replace(pos, count, repl_str);
            count = 0;
            pos = 0;
        }
    }
}

// Optimal Solution
void URLify_optimized(std::string& s, const int& true_length)
{
    int space_count{};
    for (int i = 0; i < true_length; i++)
    {
        if (s[i] == ' ') space_count++;
    }

    int index = true_length + space_count * 2;
    for (int i = true_length - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s[index - 1] = '0';
            s[index - 2] = '2';
            s[index - 3] = '%';
            index = index - 3;
        }
        else
        {
            s[index - 1] = s[i];
            index--;
        }
    }
}




int main()
{
    std::string s = "Mr John Smith      ";
    int length = 13;
    std::cout << "string before: " << s << "\n";
    URLify_optimized(s, length);
    std::cout << "string after: " << s << "\n";
    return 0;
}
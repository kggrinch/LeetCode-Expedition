#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <utility>

// Time Complexity: 2 + n = O(n)
std::string encode(std::vector<std::string>& strs)
{
    // create a string variable
    // loop through the string vector and each string character inserting the character into the string variable
    // return string variable
    std::string newString; // 1

    for(auto& s : strs) // n
    {
        newString += std::to_string(s.length()) + "#" + s; // 1
    }

    return newString; // 1
}

// Time Complexity: O(n)
// Space Complexity:
std::vector<std::string> decode(std::string s)
{
    // Create a return vector holding string type
    // Create a temp string to hold each string
    // iterate through each character of the string appending the characters in the temp string with the amount of times the maps size holds
    std::string temp{}; // 1
    std::vector<std::string> res; // 1
    int n = s.length(); // 1

    // n - iterating through each string
    for(int i = 0; i < n;)
    {
        int j = i; // m = n
        while(s[j] != '#') // m - size of the string
        {
            j++;
        }
        std::string number = s.substr(i, j - i); //  This wil
        int word_length = std::stoi(number);
        res.push_back(s.substr(j + 1, word_length));
        i = j + word_length + 1; // n +=
    }

    return res;

    //4#neet4#code4#love3#you
    //0123456789  13

    // 2#we3#say1#:3#yes10#!@#$%^&*()
    // 0123456789

}



int main()
{
    std::vector<std::string> input = {"we","say",":","yes","!@#$%^&*()"};
    std::string encodedString = encode(input);
    std::cout << encodedString << "\n";

    std::vector<std::string> output = decode(encodedString);
    for(auto& s : output)
    {
        std::cout << s << "\n";
    }


    return 0;
}

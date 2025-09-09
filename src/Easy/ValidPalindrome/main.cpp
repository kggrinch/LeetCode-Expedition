#include <iostream>

bool isPalindrome(std::string s)
{
    // Problem
    // 1. Check if a string phrase converted into one string is a palaindrome
    // 2. All uppercase letter must be converted to lower case
    // 3. All Alphanumeric characters must be removed
    //    Alphanumeric characters = 1 2 3 | , | . | anything other than a letter
    // 4. return a bool indicating if it's a palindrome

    // Ideas
    // 1. Use two pointers one starting at the first index and one at the last index and increment them toward the middle
    //    comparing each letter. O(n)
    // 2. Use a stack. Place the string in the stack and then iterate through the string while popping the stack and comparing the letters O(n)

    // Ideas on removing Alphanumeric characters and lowercasing everything
    // 1.  iterate through the string and building a new string without the alphanumeric characters and lowercasing everything

    // Build the new string without uppercases and alphanumeric values
    std::string new_s{};
    for(char& c : s) // O(n)
    {
        // Check if not a lowercase letter
        int x = c - 'a';
        if(x < 0 || x > 25) // Uppercase or alphanumeric character
        {

            int a = c - 'A';
            int b = c - '!';
            if(a >= 0 && a <= 25) // Check if uppercase letter
            {
                new_s += std::tolower(c);
            }
            else if((b >= 15 && b <= 24) || b > 93) // Check if a numeric character
            {
                new_s += c;
            }
        }
        else
        {
            new_s += c;
        }
    }

    // Check if palindrome
    if(new_s.empty()) return true;

    int first = 0;
    int last = new_s.length()- 1;
    while(first < last)
    {
        if(new_s[first] != new_s[last]) return false;
        first++;
        last--;
    }
    return true;

    // Time Complexity: O(n)
    // Space Complexity: O(n)
}

// More optimal solution with O(1) space
// Build a separate function to check if alphanumeric value
bool is_alpha_num(const char& c)
{
   return (c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= 0 && c <= '9');
}

bool isPalindromeOptimized(std::string s)
{
    int f = 0;
    int l = s.length() - 1;

    // Iterate through the characters of the string
    while(f < l)
    {
        // If a character at f is a non-alphanumeric then skip it
        while(!is_alpha_num(s[f]))
        {
            f++;
        }
        // If a character at l is a non-alphanumeric then skip it
        while(!is_alpha_num(s[f]))
        {
            l--;
        }
        // compare the characters at each index
        if(std::tolower(s[f]) != std::tolower(s[l])) return false; // if they don't match return false not palindrome
        f++;
        l--;
    }
    return true; // return true if reach the end. All characters matched

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}


int main()
{
    std::string word = "0P";
    std::cout << isPalindrome(word) << "\n";

    std::string word2 = "0P";
    std::cout << isPalindromeOptimized(word) << "\n";

    return 0;
}

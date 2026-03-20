#include <iostream>

// Time Complexity: O(n^2)
// Space Complexity: O(1)
std::string longestPalindrome(std::string s)
{
    std::string result{};
    int result_length{};
    for (int i = 0; i < s.length(); i++) // treat each index as center
    {
        // odd
        int l = i;
        int r = i;
        while (l >= 0 && r <= s.length() && s[l] == s[r])
        {
            int cur_pal_length = r - l + 1;
            if (cur_pal_length > result_length)
            {
                result = s.substr(l, cur_pal_length);
                result_length = cur_pal_length;
            }
            l--;
            r++;
        }

        // even
        l = i;
        r = i + 1;
        while (l >= 0 && r <= s.length() && s[l] == s[r])
        {
            int cur_pal_length = r - l + 1;
            if (cur_pal_length > result_length)
            {
                result = s.substr(l, cur_pal_length);
                result_length = cur_pal_length;
            }
            l--;
            r++;
        }
    }
    return result;
}

// aba
// l = 0
// r = 2
// i = 1

// length = r - l + 1
//        = 2 - 0 + 1





int main()
{
    std::string input = "ababd";
    std::cout << "length: " << input.length() << " size: " << input.size() << "\n";
    std::cout << longestPalindrome(input) << std::endl;
    return 0;
}
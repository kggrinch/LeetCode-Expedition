#include <iostream>
#include <unordered_map>
#include <vector>

bool isAnagram(std::string s, std::string t)
{
    if(s.length() != t.length()) return false;

    std::unordered_map<char, int> s_count;
    std::unordered_map<char, int> t_count;

    for(int i = 0; i < s.length(); i++)
    {
        s_count[s[i]]++;
        t_count[t[i]]++;
    }
    return s_count == t_count;

}

// Most optimimal solution
bool isAnagram2(std::string s, std::string t)
{
    // Uses vector count frequency
    // How it works is it creates a vector of 26 spaces for the 26 lower cases letters.
    // each index represents a letter and each index will be incremented base on weather the letter exists.
    // For example: a string = "anagram" will have the following vector frequency:
    // charCnt =    {3, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
//index represents   a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
    std::vector<int> charCnt(26, 0);

    // Loop through the first string and increment the number of letter occurences
    // 'a' - 'a' = 0, 'b' - 'a' = 1, ect
    for (char ch : s) charCnt[ch-'a']++;

    // Loop through the second string and decrement the indexes
    for (char ch : t)
    {
        charCnt[ch-'a']--;
        if (charCnt[ch-'a'] < 0) return false; // If an index goes below 0 then they are not an anagram
    }

    // After finishing if all indexes are not 0 then the strings are not an anagram
    for (int c: charCnt)
    {
        if (c != 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    bool yes = isAnagram2("aa", "a");
    if(yes)
    {
        std::cout << "True\n";
    }
    else
    {
        std::cout << "False\n";
    }
    return 0;
}

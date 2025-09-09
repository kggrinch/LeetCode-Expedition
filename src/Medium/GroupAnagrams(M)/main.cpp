#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Sorting appraoch
// Time Complexity: O(m * nlogn)
// Space Complexity: O(m * n)
// m = number of strings
// n = size of the longest string
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
    // Create a hashmap key = string, value = vector with all the strings
    // run through the passed in vector and save a separate string at each iteration
    // sort that saved string and add it as the key in the hashmap and add the non sorted string as a value in the vector
    // after iterating through each string create a 2d vector and iterate through the hashmap
    // save each value which is the vector holding all the combined strings into the 2d vector
    // return result.

    std::unordered_map<std::string, std::vector<std::string>> res; // S: m = at most m unique keys | n = greatest character length of a string

    for(auto& s : strs) // T: O(m)
    {
        std::string sorted_s = s; // T: (1)
        std::sort(sorted_s.begin(), sorted_s.end()); // T: Sorting: n log(n)
        res[sorted_s].push_back(s); // T: (1)
    }

    std::vector<std::vector<std::string>> result; // S: same as the unordered map
    for(auto& r : res) // T: O(m)
    {
        result.push_back(r.second);
    }
    return result;

    // Time Complexity
    // O(f(n)) = m * (2 + nlogn) + m
    //         = m * (n log n) + m
    //         = m * (n log n)
    //         = O(m * nlogn)

    // Space Complexity:
    // O(f(n)) = (m * n) + (m * n)
    //         = (m * n)
    //         = O(m * n)
}

// Most optimal approach using hashmap and character frequencies

// Time Complexity: O(m * n)
// Space Complexity: O(m) - Might be O(m * n) - since in worst case there can be m unqiue strings with n unique charaters for longest string
// m = number of strings
// n = size of the longest string

// DSA used: 1. std::unordered_map<std::string, std::vector<std::string>>
//           2. std::vector<int>
//           3. std::vector<std::vector<std::string>>
std::vector<std::vector<std::string>> groupAnagrams2(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> res;

    for(auto& s : strs) // T: m
    {
        std::vector<int> count(26, 0); // 1
        for(auto& c : s) // T: n
        {
            count[c - 'a']++;
        }
        std::string key = std::to_string(count[0]); // 1

        for(int i = 1; i < 26; ++i) // 26
        {
            key += "," + std::to_string(count[i]);
        }
        res[key].push_back(s); // 1
    }

    std::vector<std::vector<std::string>> result;
    for(auto& r : res) // m
    {
        result.push_back(r.second);
    }
    return result; // 1

    // Time Complexity:
    // O(f(n)) = m * (1 + n + 1 + 26 + 1) + m + 1
    //         = m * (n + 28) + m + 1
    //         = (m * n)
    //         = O(m * n)

    // Space Complexity:
    // O(f(n)) = ?

}


// Most optimial soultions on leetcode
// Time Complexity: O(m * n)
std::string helper(std::string &str){
    int hash[26] = {0};

    for(int i=0 ; i<str.length() ; i++){
        hash[str[i]-'a']++;
    }

    std::string ans = "";
    for(int i=0 ; i<26 ; i++){
        while(hash[i] > 0){
            ans += i+'a';
            hash[i]--;
        }
    }
    return ans;
}
std::vector<std::vector<std::string>> groupAnagram3(std::vector<std::string>& strs)
{
    std::vector<std::vector<std::string>>ans;
    std::unordered_map<std::string , std::vector<std::string>>mp;
    int n = strs.size();

    for(int i=0 ; i<n ; i++){
        std::string t = helper(strs[i]);
        mp[t].push_back(strs[i]);
    }


    for(auto i : mp){
        ans.push_back(i.second);
    }
    return ans;
}


int main()
{
    std::vector<std::string> input = {"bdddddddddd","bbbbbbbbbbc"};
    std::vector<std::vector<std::string>> result = groupAnagram3(input);

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

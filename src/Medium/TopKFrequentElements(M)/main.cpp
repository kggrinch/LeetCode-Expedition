#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <queue>
std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
    std::map<int, int> count;
    for(auto& n : nums)
    {
        count[n]++;
    }

    std::vector<std::pair<int, int>> order;
    for(auto& c : count)
    {
        order.push_back({c.second, c.first});
    }
    std::sort(order.rbegin(), order.rend()); // sort it reverse order. largest to smallest

    std::vector<int> result;
    int end = 0;
    for(int i = 0; i < k; ++i)
    {
        result.push_back(order[i].second);
    }
    return result;
}

// Better solution
std::vector<int> topKFrequent2(std::vector<int>& nums, int k)
{
    std::unordered_map<int,int> m;
    std::priority_queue<std::pair<int,int>> s;
    std::vector<int> v;
    for(int i= 0 ; i < nums.size() ; ++i)
    {
        m[nums[i]]++;
    }

    for(auto i : m)
    {
        s.push({i.second,i.first});
    }

    int cnt = 0;
    while(!s.empty())
    {
        if(cnt == k)
            break;
        std::pair<int,int> tmp = s.top();
        s.pop();
        v.push_back(tmp.second);
        ++cnt;
    }
    return v;
}


int main()
{
    // Problem given an array with recreating integers and an integer k. Return the ints that are k most frequent elemnts.
    // This problem can be read as follows given an array = {1, 2, 2, 3, 3, 3}  and given a int k = 2, give me the 2 most frequent elements in the array


    // Solution
    // Use a hashmap and store key value pairs
    // key is going to be the value in the array
    // value is going to be an integer reprinting the amount the key is in the array
    // Iteratee through the array and store the key values into a hashmap while incrementing the value if the same key approached
    std::vector<int> nums = {1,1,1,2,2,3};
    std::vector<int> result = topKFrequent(nums, 2);
    for(auto& r : result)
    {
        std::cout << r << " ";
    }
    std::cout << "\n";
    return 0;
}

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

// Time Complexity: O(n + p) | n = number of course | p = number of prerequisites
// Space Complexity: O(n + p)
bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
    std::unordered_map<int, std::vector<int>> map;
    bool fail{};
    for (auto& p : prerequisites) // p
    {
        map[p[0]].push_back(p[1]);
    }

    auto dfs = [&](int course, std::set<int>& visited, auto& dfs) -> void // n + p
    {
        visited.insert(course);
        for (auto& n : map[course])
        {
            if (visited.count(n)) {fail=true; break;}
            dfs(n, visited, dfs);
        }
        visited.erase(course);
        map[course].clear();
    };

    for (int i = 0; i < numCourses; i++) // n
    {
        if (fail) return false;
        std::set<int> visited;
        dfs(i, visited, dfs);
    }

    return true;
}

int main()
{
    int numCourses = 4;
    std::vector<std::vector<int>> pre = {
        {2,0},
        {1,0},
        {3,1},
        {3,2},
        {1,3}
    };




    std::cout << canFinish(numCourses, pre) << std::endl;
    return 0;
}
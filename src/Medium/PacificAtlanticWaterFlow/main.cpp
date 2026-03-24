#include <iostream>
#include <vector>
#include <queue>
#include <set>

// top right and bottom left = correct nodes right away

// Time Complexity: O((r * c)^2)
// Space Complexity: O(v)
std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights)
{
    std::vector<std::vector<int>> result;
    if (heights.size() == 0) return result;
    int r_size = heights.size();
    int c_size = heights[0].size();

    for (int i = 0; i < heights.size(); i++)
    {
        for (int j = 0; j < heights[0].size(); j++)
        {
            bool pacific_reached{}, atlantic_reached{}, found{};

            // dfs
            std::set<std::pair<int, int>> visited;
            std::vector<std::pair<int,int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // top, bottom, left, right

            auto dfs = [&](std::pair<int,int> cur_node, bool& found, auto& dfs)
            {
                visited.insert(cur_node);

                // Check if any oceans reached
                if ( (cur_node.second >= 0 && cur_node.second < c_size && cur_node.first == 0) || (cur_node.second == 0 && cur_node.first >= 0 && cur_node.first < r_size) ) pacific_reached = true;
                if ( (cur_node.second >= 0 && cur_node.second < c_size && cur_node.first == r_size - 1) || (cur_node.second == c_size - 1 && cur_node.first >= 0 && cur_node.first < r_size)) atlantic_reached = true;
                if (pacific_reached && atlantic_reached)
                {
                    found = true;
                    return;
                }

                // run through neighbors
                for (std::pair<int, int> d_node : directions)
                {
                    std::pair<int, int> n_node(cur_node.first + d_node.first, cur_node.second + d_node.second);
                    if(n_node.first >= 0 && n_node.first < r_size && n_node.second >= 0 && n_node.second < c_size && heights[cur_node.first][cur_node.second] >= heights[n_node.first][n_node.second] && !visited.count(n_node))
                    {
                        dfs(n_node, found, dfs);
                    }
                    if (found) return;
                }
            };
            dfs({i, j}, found, dfs);
            if (found) result.push_back({i, j});
        }
    }
    return result;
}
// (0, 0)
// (r, c)

int main()
{
    std::vector<std::vector<int>> heights =
    {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    std::vector<std::vector<int>> result =  pacificAtlantic(heights);
    return 0;
}
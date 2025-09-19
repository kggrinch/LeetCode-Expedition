#include <iostream>
#include <vector>
#include <set>

// Time Complexity: O(n logn) where n = number of rows * number of columns + time it takes to insert and look up coordinate in set
// Space Complexity: O(n) where n = number of rows * number of columns
int numIslands(std::vector<std::vector<char>>& grid)
{
    int r = grid.size();
    int c = grid[0].size();
    std::vector<std::pair<int, int>> directions= {{0, -1}, {-1,0}, {0, 1}, {1, 0}};
    int count{};

    std::set<std::pair<int, int>> visited;

    // traversal algorithm
    auto dfs = [&](std::pair<int, int> node, auto& dfs) -> void
    {
        visited.insert(node);
        for(std::pair<int, int> d_node : directions)
        {
            std::pair<int, int> n_node = {node.first + d_node.first, node.second + d_node.second};
            if(n_node.first >= 0 && n_node.second >= 0 && n_node.first < r && n_node.second < c && grid[n_node.first][n_node.second] == '1' && visited.count({n_node.first, n_node.second}) != 1)
            {
                dfs(n_node, dfs);
            }
        }
    };

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(grid[i][j] == '1' && visited.count({i, j}) != 1)
            {
                dfs({i, j}, dfs);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    std::vector<std::vector<char>> grid =
    {
        {'1','1','0','0','1'},
        {'1','1','0','0','1'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
    };

    std::cout << numIslands(grid);
    return 0;
}

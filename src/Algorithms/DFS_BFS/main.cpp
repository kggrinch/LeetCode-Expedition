#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <set>
#include <variant>


/*?
? ---------------------
? Breadth First Search
?----------------------
??/d

/**
 * Breadth First Search (Graph - Adjacency List)
 * */
// Standard Implementation: Queue + Vector<bool>
// Pros: Efficient and standard implementation
// Cons: Requires nodes to use a continuous label like 0 = node 0, 1 = node 1
void bfs_adjacency_list_standard(int start, std::vector<std::vector<int>>& adj)
{
    int vertices = adj.size();

    std::vector<bool> visited(vertices, false);
    std::deque<int> queue;

    queue.push_back(start);
    visited[start] = true;

    while(!queue.empty())
    {
        int node = queue.front();
        queue.pop_front();

        std::cout << node << " ";

        // Iterate through nodes neighbors
        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }
}

// Secondly Implementation: Queue + Set
// Pros: No fixed size needed and works well if graph nodes are not continuous labels, but are arbitrary label (like strings, large ids, or node objects)
// Cons: Requires more memory and not default implementation
// Note: C++20 and below do not offer the .contains function on sets therefore use .count != 1 to check if the element exits in a set
void bfs_adjacency_list_secondary(int start, std::vector<std::vector<int>>& adj)
{
    std::unordered_set<int> visited;
    std::deque<int> queue;

    queue.push_back(start);
    visited.insert(start);

    while(!queue.empty())
    {
        int node = queue.front();
        queue.pop_front();

        std::cout << node << " ";

        // Iterate through nodes neighbors
        for(int neighbor : adj[node])
        {
            if(!visited.contains(neighbor))
            {
                visited.insert(neighbor);
                queue.push_back(neighbor);
            }
        }
    }
}

/**
 * Breadth First Search (Graph - Matrix)
 * */
// Standard Implementation: Queue + Vector<bool>
// Pros: Efficient and standard implementation
// Cons: Requires nodes to use a continuous label like 0 = node 0, 1 = node 1
void bfs_matrix_standard(int start, std::vector<std::vector<int>>& matrix)
{
    int vertices = matrix.size();

    std::vector<bool> visited(vertices, false);
    std::deque<int> queue;

    queue.push_back(start);
    visited[start] = true;

    while(!queue.empty())
    {
        int node = queue.front();
        queue.pop_front();

        std::cout << node << " ";

        // Iterate through nodes neighbors
        for(int neighbor = 0; neighbor < vertices; neighbor++)
        {
            if(matrix[node][neighbor] && !visited[neighbor])
            {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }
}

// Secondary Implementation: Queue + Set
// Pros: No fixed size needed and works well if graph nodes are not continuous labels, but are arbitrary label (like strings, large ids, or node objects)
// Cons: Requires more memory and not default implementation
// Note: C++20 and below do not offer the .contains function on sets therefore use .count != 1 to check if the element exits in a set
void bfs_matrix_secondary(int start, std::vector<std::vector<int>>& matrix)
{
    int vertices = matrix.size();

    std::unordered_set<int> visited;
    std::deque<int> queue;

    queue.push_back(start);
    visited.insert(start);

    while(!queue.empty())
    {
        int node = queue.front();
        queue.pop_front();

        std::cout << node << " ";

        // Iterate through nodes neighbors
        for(int neighbor = 0; neighbor < vertices; neighbor++)
        {
            if(matrix[node][neighbor] && !visited.contains(neighbor))
            {
                visited.insert(neighbor);
                queue.push_back(neighbor);
            }
        }
    }
}

/**
 * Breadth First Search (Grid)
 * */
// Standard Implementation: Queue + Vector<bool>
// Pros: Efficient and standard implementation
// Cons: Requires nodes to use a continuous label like 0 = node 0, 1 = node 1
// This uses pairs with the dsa
void bfs_grid_standard(std::pair<int, int> start, std::vector<std::vector<int>>& grid)
{
    int r = grid.size(); // rows
    int c = grid[0].size(); // columns

    std::deque<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(r, std::vector<bool>(c, false));

    // left, top, right, bottom
    std::vector<std::pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    q.push_back(start);
    visited[start.first][start.second] = true;

    while(!q.empty())
    {
        std::pair<int, int> node = q.front();
        q.pop_front();

        std::cout << "(" << node.first << ", " << node.second << ") ";

        for(std::pair<int, int> d_node : directions)
        {
            std::pair<int, int> n_node = {node.first + d_node.first, node.second + d_node.second};
            if(n_node.first >= 0 && n_node.second >= 0 && n_node.first < r && n_node.second < c && grid[n_node.first][n_node.second] && !visited[n_node.first][n_node.second])
            {
                visited[n_node.first][n_node.second] = true;
                q.push_back(n_node);
            }
        }
    }
}

// Secondary Implementation: Queue + Set
// Pros: No fixed size needed and works well if graph nodes are not continuous labels, but are arbitrary label (like strings, large ids, or node objects)
// Cons: Requires more memory and not default implementation. Requires organized set
// Note: This implementation uses pairs but in a unique way where we retrieve the two values in the pair and uses them separately
// Note: C++20 and below do not offer the .contains function on sets therefore use .count != 1 to check if the element exits in a set
void bfs_grid_secondary(std::pair<int, int> start, std::vector<std::vector<int>>& grid)
{
    int r = grid.size();
    int c = grid[0].size();

    std::deque<std::pair<int, int>> q;
    std::set<std::pair<int, int>> visited; // requires default set (cannot use unordered because cannot hash pair)
    std::vector<std::pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    q.push_back(start);
    visited.insert(start);

    while(!q.empty())
    {
        const auto& [c_row, c_col] = q.front();
        q.pop_front();

        std::cout << "(" << c_row << ", " << c_col << ") ";

        for(const auto& [d_row, d_col] : directions)
        {
            int n_row = c_row + d_row;
            int n_col = c_col + d_col;
            if(n_row >= 0 && n_col >= 0 && n_row < c && n_col < r && grid[n_row][n_col] && !visited.contains({n_row, n_col}))
            {
                q.push_back({n_row, n_col});
                visited.insert({n_row, n_col});
            }
        }
    }
}

/*?
? ---------------------
? Depth First Search
?----------------------
?*/

// Note: dfs has some different ways that it can be implemented:
// 1. dfs helper function calls a helper recursive function inside the function
//      - Pros: efficient
//      - Cons: requires more things to be passed into the recursive parameters
// 2. dfs with an anonymous function inside the function
//      - Pros: requires fewer things to be passed into the recursive parameters (references everything from the function)
//      - Cons: less efficient than a direct helper function.
// 3. iterative dfs
//      - Pros: No risk of stack overflow, easier control and debugging, and consistent performance
//      - Cons: less intuitive to design, manual stack control, more complex backtracking management.


//! Depth First Search Recursive Helpers

// Adjacency List
// dfs adjacency list helper recursive function with (vector<bool> visited)
void dfs_adjacency_list_standard_helper(int node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited)
{
    visited[node] = true;
    std::cout << node << " ";

    for(int neighbor : adj[node])
    {
        if(!visited[neighbor])
        {
            dfs_adjacency_list_standard_helper(neighbor, adj, visited);
        }
    }
}

// Adjacency List
// dfs adjacency list helper recursive function with (Set visited)
// Note: C++20 and below do not offer the .contains function on sets therefore use .count != 1 to check if the element exits in a set
void dfs_adjacency_list_secondary_helper(int node, const std::vector<std::vector<int>>& adj, std::unordered_set<int>& visited)
{
    visited.insert(node);
    std::cout << node << " ";

    for(int neighbor: adj[node])
    {
        if(!visited.contains(neighbor))
        {
            dfs_adjacency_list_secondary_helper(neighbor, adj, visited);
        }
    }
}

// Matrix
// dfs matrix helper recursive function with (vector<bool> visited)
void dfs_matrix_standard_helper(int node, const std::vector<std::vector<int>>& matrix, std::vector<bool>& visited)
{
    visited[node] = true;
    std::cout << node << " ";

    for(int neighbor = 0; neighbor < matrix.size(); neighbor++)
    {
        if(matrix[node][neighbor] && !visited[neighbor])
        {
            dfs_matrix_standard_helper(neighbor, matrix, visited);
        }
    }
}

// Matrix
// dfs matrix helper recursive function with (Set visited)
// Note: C++20 and below do not offer the .contains function on sets therefore use .count != 1 to check if the element exits in a set
void dfs_matrix_secondary_helper(int node, const std::vector<std::vector<int>>& matrix, std::unordered_set<int>& visited)
{
    visited.insert(node);
    std::cout << node << " ";

    for(int neighbor = 0; neighbor < matrix.size(); neighbor++)
    {
        if(matrix[node][neighbor] && !visited.contains(neighbor))
        {
            dfs_matrix_secondary_helper(neighbor, matrix, visited);
        }
    }
}


// Grid
// dfs matrix helper recursive function with (vector<bool> visited)
void dfs_grid_standard_helper(std::pair<int, int> node, const std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited)
{
    // Save grid row and column sizes
    int r = grid.size();
    int c = grid[0].size();

    // Save current node coordinate
    int c_r = node.first;
    int c_c = node.second;

    if(c_r < 0 || c_c < 0 || c_r >= r || c_c >= c || !grid[c_r][c_c] || visited[c_r][c_c]) return;

    visited[c_r][c_c] = true;
    std::cout << "(" << c_r << ", " << c_c << ") ";
    std::vector<std::pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    for(const auto& [d_r, d_c] : directions)
    {
        dfs_grid_standard_helper({c_r + d_r, c_c + d_c}, grid, visited);
    }
}

// Grid
// dfs matrix helper recursive function with (Set visited)
// Note: C++20 and below do not offer the .contains function on sets therefore use .count != 1 to check if the element exits in a set
void dfs_grid_secondary_helper(std::pair<int, int> node, const std::vector<std::vector<int>>& grid, std::set<std::pair<int, int>>& visited)
{
    int r = grid.size();
    int c = grid[0].size();

    if(node.first < 0 || node.second < 0 || node.first >= r || node.second >= c || !grid[node.first][node.second] || visited.contains(node)) return;

    visited.insert(node);
    std::cout << "(" << node.first << ", " << node.second << ") ";
    std::vector<std::pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    for(std::pair<int, int> d_node : directions)
    {
        dfs_grid_secondary_helper({node.first + d_node.first, node.second + d_node.second}, grid, visited);
    }
}


/**
 * Depth First Search (Graph - Adjacency List)
 * */

// Standard Implementation: Queue + Vector<bool>
// Pros: Efficient and standard implementation
// Cons: Requires nodes to use a continuous label like 0 = node 0, 1 = node 1
// Note: The dfs implementation uses the 2nd design.
void dfs_adjacency_list_standard(int start, const std::vector<std::vector<int>>& adj)
{
    int vertices = adj.size();
    std::vector<bool> visited(vertices, false);

    auto dfs = [&](int node, auto& dfs) -> void
    {
        visited[node] = true;
        std::cout << node << " ";
        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                dfs(neighbor, dfs);
            }
        }
    };

    dfs(start, dfs);
}

// Secondary Implementation: Queue + Set
// Pros: No fixed size needed and works well if graph nodes are not continuous labels, but are arbitrary label (like strings, large ids, or node objects)
// Cons: Requires more memory and not default implementation. Requires organized set
// Note: This implementation uses the 1st design
// Note: C++20 and below do not offer the .contains function on sets therefore use .count != 1 to check if the element exits in a set
void dfs_adjacency_list_secondary(int start, std::vector<std::vector<int>> adj)
{
    std::unordered_set<int> visited;
    dfs_adjacency_list_secondary_helper(start, adj, visited);
}


/**
 * Depth First Search (Graph - Matrix)
 * */

// Standard Implementation: Queue + Vector<bool>
// Pros: Efficient and standard implementation
// Cons: Requires nodes to use a continuous label like 0 = node 0, 1 = node 1
// Note: The dfs implementation uses the 1st design.
void dfs_matrix_standard(int start, const std::vector<std::vector<int>>& matrix)
{
    int vertices = matrix.size();
    std::vector<bool> visited(vertices, false);
    dfs_matrix_standard_helper(start, matrix, visited);
}

// Secondary Implementation: Queue + Set
// Pros: No fixed size needed and works well if graph nodes are not continuous labels, but are arbitrary label (like strings, large ids, or node objects)
// Cons: Requires more memory and not default implementation. Requires organized set
// Note: This implementation uses the 2nd design
// Note: C++20 and below do not offer the .contains function on sets therefore use .count != 1 to check if the element exits in a set
void dfs_matrix_secondary(int start, const std::vector<std::vector<int>>& matrix)
{
    std::unordered_set<int> visited;
    const int vertices = matrix.size();

    auto dfs = [&](int node, auto& dfs) -> void
    {
        visited.insert(node);
        std::cout << node << " ";

        for(int neighbor = 0; neighbor < vertices; neighbor++)
        {
            if(matrix[node][neighbor] && !visited.contains(neighbor))
            {
                dfs(neighbor, dfs);
            }
        }
    };

    dfs(start, dfs);
}


/**
 * Depth First Search (Grid)
 * */

// Standard Implementation: Queue + Vector<bool>
// Pros: Efficient and standard implementation
// Cons: Requires nodes to use a continuous label like 0 = node 0, 1 = node 1
// Note: The dfs implementation uses the 1st design.
void dfs_grid_standard(std::pair<int, int> start, const std::vector<std::vector<int>>& grid)
{
    int r = grid.size();
    int c = grid[0].size();
    std::vector<std::vector<bool>> visited(r, std::vector<bool>(c, false));
    dfs_grid_standard_helper(start, grid, visited);
}

// Secondary Implementation: Queue + Set
// Pros: No fixed size needed and works well if graph nodes are not continuous labels, but are arbitrary label (like strings, large ids, or node objects)
// Cons: Requires more memory and not default implementation. Requires organized set
// Note: This implementation uses the 2nd design
// Note: C++20 and below do not offer the .contains function on sets therefore use .count != 1 to check if the element exits in a set
void dfs_grid_secondary(std::pair<int, int> start, const std::vector<std::vector<int>>& grid)
{
    int r = grid.size();
    int c = grid[0].size();
    std::set<std::pair<int, int>> visited;
    std::vector<std::pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    auto dfs = [&](std::pair<int, int> node, auto& dfs) -> void
    {
        visited.insert(node);
        std::cout << "(" << node.first << ", " << node.second << ") ";

        for(std::pair<int, int> d_node : directions)
        {
            std::pair<int, int> n_node({node.first + d_node.first, node.second + d_node.second});
            if(n_node.first >= 0 && n_node.second >= 0 && n_node.first < r && n_node.second < c && grid[n_node.first][n_node.second] && !visited.contains(n_node))
            {
                dfs(n_node, dfs);
            }
        }
    };

    dfs(start, dfs);
}


int main()
{
    // Graph template
    // 0 - 1 - 3
    //  \ /    |
    //   2  -  4

    // Adjacent List
    // graph template
    // 0 -> 1, 2
    // 1 -> 0, 2, 3
    // 2 -> 0, 1, 4
    // 3 -> 1, 4
    // 4 -> 2, 3

    int n = 5; // number of nodes
    std::vector<std::vector<int>> adj(n);
    adj[0] = {1,2};
    adj[1] = {0,2,3};
    adj[2] = {0,1,4};
    adj[3] = {1, 4};
    adj[4] = {2, 3};

    // Matrix
    // graph template
    //   0 1 2 3 4
    // 0 0 1 1 0 0
    // 1 1 0 1 1 0
    // 2 1 1 0 0 1
    // 3 0 1 0 0 1
    // 4 0 0 1 1 0

    int m = 5;
    std::vector<std::vector<int>> matrix(n,  std::vector<int>(n, 0));
    // undirected edges
    matrix[0][1] = matrix[1][0] = 1;
    matrix[0][2] = matrix[2][0] = 1;
    matrix[1][3] = matrix[3][1] = 1;
    matrix[1][2] = matrix[2][1] = 1;
    matrix[2][4] = matrix[4][2] = 1;
    matrix[3][4] = matrix[4][3] = 1;

    // Grid
    // grid template
    // 1 1 1
    // 1 1 0
    // 0 1 1

    std::vector<std::vector<int>> grid =
    {
        {1, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    std::pair<int, int> start = {0, 0};

    //? Breadth First Search

    //* Breadth First Search (Graph - Adjacency List)
    std::cout << "Breadth First Search\n\n";

    // Standard Implementation: Queue + Vector<bool>
    std::cout << "(Graph - Adjacency List)(bfs)\n";
    std::cout << "Standard Implementation: Queue + Vector<bool>\n";
    bfs_adjacency_list_standard(0, adj);
    std::cout << "\n\n";

    // secondary Implementation: Queue + Set
    std::cout << "secondary Implementation: Queue + Set\n";
    bfs_adjacency_list_secondary(0, adj);
    std::cout << "\n\n";

    //* Breadth First Search (Graph - Matrix)
    std::cout << "(Graph - Matrix)(bfs)\n";
    std::cout << "Standard Implementation: Queue + Vector<bool>\n";
    bfs_matrix_standard(0, matrix);
    std::cout << "\n\n";

    std::cout << "secondary Implementation: Queue + Set\n";
    bfs_matrix_secondary(0, matrix);
    std::cout << "\n\n";

    //* Breadth First Search (Grid)
    std::cout << "(Grid)(bfs)\n";
    std::cout << "Standard Implementation: Queue + Vector<bool>\n";
    bfs_grid_standard(start, grid);
    std::cout << "\n\n";

    std::cout << "secondary Implementation: Queue + Set\n";
    bfs_grid_secondary(start, grid);
    std::cout << "\n\n";

    //? Depth First Search

    //* Depth First Search (Graph - Adjacency List)
    std::cout << "Depth First Search\n\n";

    // Standard Implementation: Queue + Vector<bool>
    std::cout << "(Graph - Adjacency List)(bfs)\n";
    std::cout << "Standard Implementation: Queue + Vector<bool>\n";
    dfs_adjacency_list_standard(0, adj);
    std::cout << "\n\n";

    // Secondary Implementation: Queue + Vector<bool>
    std::cout << "Secondary Implementation: Queue + Set\n";
    dfs_adjacency_list_secondary(0, adj);
    std::cout << "\n\n";

    //* Depth First Search (Graph - Matrix)
    std::cout << "(Graph - Matrix)(dfs)\n";
    std::cout << "Standard Implementation: Queue + Vector<bool>\n";
    dfs_matrix_standard(0, matrix);
    std::cout << "\n\n";

    std::cout << "secondary Implementation: Queue + Set\n";
    dfs_matrix_secondary(0, matrix);
    std::cout << "\n\n";

    //* Depth First Search (Grid)
    std::cout << "(Grid)(dfs)\n";
    std::cout << "Standard Implementation: Queue + Vector<bool>\n";
    dfs_grid_standard(start, grid);
    std::cout << "\n\n";

    std::cout << "secondary Implementation: Queue + Set\n";
    dfs_grid_secondary(start, grid);
    std::cout << "\n\n";

    return 0;
}

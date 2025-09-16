#include <iostream>
#include <vector>
#include <deque>


// Breadth First Search (Graph - Adjacency List)
void bfs_adjacency_list(int start, std::vector<std::vector<int>>& adj, std::vector<bool>& visited)
{
    std::deque<int> q;
    q.push_back(start);
    visited.push_back(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop_back();

        std::cout << node << " ";

        // Iterate through nodes neighbors
        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push_back(neighbor);
            }
        }
    }
}




int main()
{
    // Graph Example
    int n = 5;
    std::vector<std::vector<int>> adj(n);
    adj[0] = {1,2};
    adj[1] = {0,3,4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    std::cout << "BFS (Graph): ";
    std::vector<bool> visited(n,false);
    bfs_adjacency_list(0, adj, visited);
    std::cout << "\n";

    return 0;
}

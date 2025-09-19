#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <variant>
#include <set>
#include <unordered_map>

struct Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// Time Complexity: O(n) where n = vertices + edges
// Space Complexity: O(n + m) where n = all old nodes and m = all new nodes
Node* cloneGraph(Node* node)
{
    // If graph is empty return nullptr
    if(!node) return nullptr;

    // Keep track of old and new nodes
    std::unordered_map<Node*, Node*> map;
    auto dfs = [&](Node* node, auto& dfs) -> Node*
    {
        // if new node already exists return it
        if(map.count(node) == 1) return map[node]; // Note: ide < C++20 does not include map.contains() function so use map.count()

        // If new node does not exist create it, store it into the map, and recurse its neighbors
        Node* new_node = new Node(node->val);
        map[node] = new_node;
        for(Node* neighbor : node->neighbors)
        {
            new_node->neighbors.push_back(dfs(neighbor, dfs));
        }
        // return new_node after saving neighbors
        return new_node;
    };

    return dfs(node, dfs);
}



int main()
{
    Node vertex1(1);
    Node vertex2(2);
    Node vertex3(3);
    Node vertex4(4);

    std::vector<Node*> v1_neighbors;
    v1_neighbors.push_back(&vertex2);
    v1_neighbors.push_back(&vertex4);

    std::vector<Node*> v2_neighbors;
    v2_neighbors.push_back(&vertex1);
    v2_neighbors.push_back(&vertex3);

    std::vector<Node*> v3_neighbors;
    v3_neighbors.push_back(&vertex2);
    v3_neighbors.push_back(&vertex4);

    std::vector<Node*> v4_neighbors;
    v4_neighbors.push_back(&vertex1);
    v4_neighbors.push_back(&vertex3);


    vertex1.neighbors = v1_neighbors;
    vertex2.neighbors = v2_neighbors;
    vertex3.neighbors = v3_neighbors;
    vertex4.neighbors = v4_neighbors;

    Node* second_graph = cloneGraph(&vertex1);
    return 0;
}

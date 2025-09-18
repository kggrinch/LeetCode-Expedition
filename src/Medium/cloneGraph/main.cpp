#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <variant>

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


Node* cloneGraph(Node* node)
{
    std::deque<Node*> q_original;
    std::unordered_set<Node*> visited_original;
    std::unordered_set<Node*> visited_new;
    std::deque<Node*> q_new;

    q_original.push_back(node);
    visited_original.insert(node);

    Node* new_node = nullptr;
    q_original.push_back(new_node);
    visited_original.insert(new_node);

    while(!(q_original.empty()) && !(q_new.empty()))
    {
        Node* cur_node = q_original.front();
        if(!q_new.front()) Node* new_node = new Node(cur_node->val);
        else Node* new_node = q_new.front();
        q_original.pop_back();
        q_new.pop_back();

        for(Node* neighbor : cur_node->neighbors)
        {
            if(visited_original.count(neighbor) != 1)
            {
                visited_original.insert(neighbor);
                q_original.push_back(neighbor);

                new_node->neighbors.push_back(new Node(neighbor->val));
            }
        }
    }
    return new_node;
}



int main()
{
    Node vertex1(1);
    Node vertex2(2);
    Node vertex3(3);

    std::vector<Node*> v1_neighbors;
    v1_neighbors.push_back(&vertex2);

    std::vector<Node*> v2_neighbors;
    v2_neighbors.push_back(&vertex1);
    v2_neighbors.push_back(&vertex3);

    std::vector<Node*> v3_neighbors;
    v3_neighbors.push_back(&vertex2);

    vertex1.neighbors = v1_neighbors;
    vertex2.neighbors = v2_neighbors;
    vertex3.neighbors = v3_neighbors;

    Node* second_graph = cloneGraph(&vertex1);
    return 0;
}

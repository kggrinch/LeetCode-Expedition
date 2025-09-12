#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Tree
{
    Tree() : root(nullptr) {}
    void createTree(std::vector<int> array_tree)
    {
        root = regular_tree_insert(array_tree, 0);
    }

    // Regular level insert
    TreeNode* regular_tree_insert(std::vector<int> array, int i)
    {
        if (i >= array.size() ) return nullptr;

        TreeNode* node = new TreeNode();
        if(array[i] != -1) node->val = array[i];
        node->left = regular_tree_insert(array, 2*i + 1);
        node->right = regular_tree_insert(array, 2*i + 2);
        return node;
    }


    TreeNode* root;
};

// Time Complexity: O(n) - visit all nodes in the tree | O(n log n) - n log n with visited set since n=all nodes and logn-time it takes to check if node is visited
// Space Complexity: O(n) - hold all nodes from tree in queue, and set
std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
    // BFS
    std::deque<TreeNode*> line;
    std::vector<std::vector<int>> result;
    // std::set<TreeNode*> visited; // No need to use since tree do not have cycles
    line.push_back(root);
    while(!line.empty())
    {
        // At current level, iterate through all nodes in the queue and save their children next in the queue
        std::vector<int> cur_level{};
        int line_length = line.size();
        // for(auto val : line) - Better to use an external counting loop than a for each, since the for each use a direct iterator from the queue
        // and the queue is modified dynamically so it can mess up the iterator.
        for(int i = 0; i < line_length; i++)
        {
            // retrieve front node and pop from queue
            TreeNode* cur_node = line.front();
            line.pop_front();
            // Push current node into level array and its children into queue if current node is not nullptr and has not been visited
            if(cur_node) // && !visited.contains(cur_node)
            {
                // visited.insert(cur_node);
                line.push_back(cur_node->left);
                line.push_back(cur_node->right);
                cur_level.push_back(cur_node->val);
            }
        }
        // add vector with all level values into result if it's not empty
        if(!cur_level.empty())result.push_back(cur_level);
    }
    return result;
}

int main()
{
    std::vector<int> tree_list1 = {1,2,3,4,5,6,7};
    std::vector<int> tree_list2 = {1, 2, 3};
    Tree tree, tree2;
    tree.createTree(tree_list1);
    tree2.createTree(tree_list2);
    std::vector<std::vector<int>> result = levelOrder(tree.root);

    return 0;
}

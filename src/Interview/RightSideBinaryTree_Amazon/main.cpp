#include <iostream>
#include <vector>
#include <queue>

// Problem: Imagine your standing on the right side of a binary tree. Print all the nodes that you would see.

// Example: Solution: [1, 3, 4]
//     1 <-
//    / \
//   2   3 <-
//  /
// 4 <-

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// BFS Solution
// Time Complexity: O(n)
// Space Complexity: O(n)
std::vector<int> right_nodes_bfs(TreeNode* root)
{
    std::vector<int> result;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        int q_size = q.size();
        std::vector<int> cur_level;
        for (int i = 0; i < q_size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if (node)
            {
                cur_level.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        result.push_back(cur_level[cur_level.size() - 1]);
    }
    return result;
}

void dfs_helper(TreeNode* node, int level, std::vector<int>& result)
{
    if (!node) return;
    if (level == result.size()) result.push_back(node->val);

    dfs_helper(node->right, level + 1, result);
    dfs_helper(node->left, level + 1, result);
}

// DFS Solution (optimized)
// Time Complexity: O(n)
// Space Complexity: O(h) h = height of the tree
std::vector<int> right_nodes_dfs(TreeNode* root)
{
    std::vector<int> result;
    auto dfs = [&](TreeNode* node, int level, auto& dfs)
    {
        if (!node) return;
        if (level == result.size()) result.push_back(node->val);

        dfs(node->right, level + 1 , dfs);
        dfs(node->left, level + 1, dfs);
    };
    dfs(root, 0, dfs);
    return result;
}


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
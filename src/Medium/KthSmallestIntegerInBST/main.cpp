#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// In-order traverse
// Time Complexity: O(n)
// Space Complexity: O(n)
int kthSmallest(TreeNode* root, int k)
{
    // in order traverse tree and save elements in sorted order into an array
    std::vector<int> sorted_tree;
    auto in_order = [&](TreeNode* root, std::vector<int>& sorted_tree, auto& in_order) -> void
    {
        if (!root) return;
        in_order(root->left, sorted_tree, in_order);
        sorted_tree.push_back(root->val);
        in_order(root->right, sorted_tree, in_order);
    };
    in_order(root, sorted_tree, in_order);
    return sorted_tree[k - 1]; // retrieve the kth smallest element (1-indexed)
}

// DFS (Optimal)
int kthSmallest_optimal(TreeNode* root, int k)
{
    std::vector<int> map(2);
    map[0] = k;

    auto dfs = [&](TreeNode* root, std::vector<int>& map, auto& dfs) -> void
    {
        if (!root) return;
        dfs(root->left, map, dfs);
        map[0]--;
        if (map[0] == 0)
        {
            map[1] = root->val;
            return;
        }
        dfs(root->right, map, dfs);
    };
    dfs(root, map, dfs);
    return map[1];
}



int main()
{
    TreeNode t1(2);
    TreeNode t2(1,nullptr, &t1);
    TreeNode t3(4);
    TreeNode t4(3, &t2, &t3);

    std::cout << kthSmallest_optimal(&t4, 1) << std::endl;
    return 0;
}
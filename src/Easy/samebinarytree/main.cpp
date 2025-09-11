#include <iostream>
#include <vector>
#include <algorithm>

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
        root = tree_insert(array_tree, 0);
    }

    TreeNode* tree_insert(std::vector<int> array, int i)
    {
        if (i >= array.size() ) return nullptr;

        TreeNode* node = new TreeNode(array[i]);
        node->left = tree_insert(array, 2*i + 1);
        node->right = tree_insert(array, 2*i + 2);
        return node;
    }

    TreeNode* root;
};

// Time complexity: O(n + m) - all p nodes and q nodes
// Space complexity: O(logn + logm) best case of balanced trees | O(n + m) - height of the tree/worse case of both trees
bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr || p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main()
{
    std::vector<int> tree_list1 = {1, 2, 3};
    std::vector<int> tree_list2 = {1, 2, 3};
    Tree tree, tree2;
    tree.createTree(tree_list1);
    tree2.createTree(tree_list2);
    std::cout << isSameTree(tree.root, tree2.root) << "\n";

    return 0;
}

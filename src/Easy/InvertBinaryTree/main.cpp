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

TreeNode* invertTree(TreeNode* root)
{
    if(root == nullptr) return nullptr;
    TreeNode* r_t = root->right;
    TreeNode* l_t = root->left;
    root->right = invertTree(l_t);
    root->left = invertTree(r_t);
    return root;
}


int main()
{
    std::vector<int> tree_list = {4,2,7,1,3,6,9};
    Tree tree;
    tree.createTree(tree_list);
    invertTree(tree.root);

    return 0;
}

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

// Time Complexity:
// Space Complexity:
int maxDepthBruteForce(TreeNode* root)
{
    if(root == nullptr) return 0; // 2
    if((root->right == nullptr && root->left == nullptr)) return 1; // 3
    return std::max(maxDepthBruteForce(root->left), maxDepthBruteForce(root->right)) + 1; //

}

// Time Complexity: O(n)
// Space Complexity: O(n)
int maxDepth(TreeNode* root)
{
    if(root == nullptr) return 0; // 1
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1; //

    // T(n) = T(n/2) + T(n/2) + 1
    //      = 2T(n/2) + 1
    //      =
    // T(n/2) = 2T((n/2)/2) + 1
    //        = 2T(n/4) + 1

    // T(n) = 2( (2T(n/4) + 1) + 1
    //      = 4T(n/4) + 3

    // T(n) = 2^kT(n/2^k) + (2^k - 1)

    // base case: T(0) = 0
    // to reach base case: n/2^k = 0 -> n = 0, however
}























int main()
{
    std::vector<int> tree_list = {1, 2, 3, 4};
    Tree tree;
    tree.createTree(tree_list);
    int max = maxDepth2(tree.root);
    std::cout << max << "\n";


    return 0;
}

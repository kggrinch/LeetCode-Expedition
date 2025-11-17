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

// Std::vector<int> vector(first iterator, last iterator);
// includes first and everything up to last iterator not including the last iterator.

// Time Complexity: O(n^2) - O(2n) per recursive algorithm and in worse case the recursion goes n deep so its O(n^2) for O(n) per recusion call.
// Space Complexity: O(n)
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    if (preorder.empty() || inorder.empty()) return nullptr;

    TreeNode* root = new TreeNode(preorder[0]);
    int mid = std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin(); // Index of root in the inorder array
    std::vector<int> pre_left(preorder.begin() + 1, preorder.begin() + mid + 1);
    std::vector<int> pre_right(preorder.begin() + mid + 1, preorder.end());
    std::vector<int> in_left(inorder.begin(), inorder.begin() + mid);
    std::vector<int> in_right(inorder.begin() + mid + 1, inorder.end());
    root->left = buildTree(pre_left, in_left);
    root->right = buildTree(pre_right, in_right);
    return root;
}

int main()
{
    std::vector<int> preorder = {6, 3, 2, 7, 1, 4, 5, 3};
    std::vector<int> inorder = {7, 2, 3, 1, 6, 5, 4, 3};
    TreeNode* root = buildTree(preorder, inorder);
    return 0;
}
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time Complexity: O(n)
// Space Complexity: O(n) - n recursive stacks
bool isValidBST(TreeNode* root)
{
    // Handle edge cases
    if (!root) return true;
    auto valid = [&](TreeNode* root, long left, long right, auto& valid) -> bool
    {
        if (!root) return true;
        if (!(left < root->val && right > root->val)) return false;
        return valid(root->left, left, root->val, valid) && valid(root->right, root->val, right, valid);
    };

    return valid(root, LONG_MIN, LONG_MAX, valid);
}



int main()
{
    TreeNode t1(2147483647);
    std::cout << isValidBST(&t1) << std::endl;
    return 0;
}
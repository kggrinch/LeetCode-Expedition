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


bool equal(TreeNode* root, TreeNode* subRoot)
{
    // Handle edge case:
    if ( (root && !subRoot) || (!root && subRoot)) return false;
    while (root && subRoot)
    {
        if (root->val != subRoot->val) return false;
        return equal(root->left, subRoot->left) && equal(root->right, subRoot->right);
    }
    return true; // both are null
}

// Time Complexity: O(n * m) where n = nodes in root | m = nodes in subroot
// Space Complexity: O(n + m) where n = nodes in root | m = nodes in subroot
bool isSubtree(TreeNode* root, TreeNode* subRoot)
{
    // Handle edge cases
    if (!root && !subRoot || (root && !subRoot)) return true;
    if (!root) return false;
    if (equal(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}


int main()
{
    TreeNode tree1_4(4);
    TreeNode tree1_5(5);
    TreeNode tree1_2(2, &tree1_4, &tree1_5);
    TreeNode tree1_3(3);
    TreeNode tree1_1(1, &tree1_2, &tree1_3);

    TreeNode tree2_4(4);
    TreeNode tree2_5(5);
    TreeNode tree2_2(2, &tree2_4, &tree2_5);

    std::cout << isSubtree(&tree1_1, &tree2_2);

    return 0;
}
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

// Practice
// Time Complexity: worse case O(n + m) (n=nodes first tree, m=nodes second tree) - check every node
// Space Complexity: worse case O(h, f) (h=tree1 height, f=tree2=height)- recursive depth as the height of the tree | average case O(logh, logf) - recursive depth split tree
bool isSameTree2(TreeNode* p, TreeNode* q)
{
    // Check if both roots are nullptr = return same
    if(!(p) && !(q)) return true;
    // Check if one of the roots is a nullptr or if the values of roots don't match = return false
    if(!(p) || !(q) || p->val != q->val) return false;
    // Check same conditions on the roots left and right children
    return (isSameTree2(p->left, q->left) && isSameTree2(p->right, q->right));
}



int main()
{
    std::vector<int> tree_list1 = {1, 2, 3};
    std::vector<int> tree_list2 = {1, 2, 3};
    Tree tree, tree2;
    tree.createTree(tree_list1);
    tree2.createTree(tree_list2);
    std::cout << isSameTree2(tree.root, tree2.root) << "\n";

    return 0;
}

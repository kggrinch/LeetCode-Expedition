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

// Time Complexity: O(logn) - avg since we travelers split bst| O(h) - worst case height of the tree
// Space Complexity: O(logn) - avg since we traverse the depth of the split bst | O(h) - worse case depth of the tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    else if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    else return root;
}


// Time Complexity: O(logn) - avg since we travelers split bst| O(h) - worst case height of the tree
// Space Complexity: O(logn) - avg since we traverse the depth of the split bst | O(h) - worse case depth of the tree
TreeNode* lowestCommonAncestor_Optimized(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode* cur = root;
    while(cur)
    {
        if(p->val < cur->val && q->val < cur->val) cur = cur->left;
        else if(p->val > cur->val && q->val > cur->val) cur = cur->right;
        else return cur;
    }
}

int main()
{
    std::vector<int> tree_list1 = {5,3,8,1,4,7,9};
    std::vector<int> tree_list2 = {1, 2, 3};
    Tree tree, tree2;
    tree.createTree(tree_list1);
    tree2.createTree(tree_list2);
    TreeNode* desc1 = new TreeNode(3);
    TreeNode* desc2 = new TreeNode(4);

    std::cout << lowestCommonAncestor_Optimized(tree.root, desc1, desc2)->val << "\n";

    return 0;
}

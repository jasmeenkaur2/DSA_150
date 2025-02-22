#include <iostream>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If root is NULL or matches p or q, return root
        if (root == nullptr || root == p || root == q) return root;

        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If p and q are found in both left and right, current root is LCA
        if (left != nullptr && right != nullptr) return root;

        // Otherwise, return the non-null subtree result
        return (left != nullptr) ? left : right;
    }
};

// Driver Code
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, root->left, root->left->right->right); // Finding LCA of (5, 4)
    
    cout << "Lowest Common Ancestor: " << lca->val << endl;  // Output: 5

    return 0;
}

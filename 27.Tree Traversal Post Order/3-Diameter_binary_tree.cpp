#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDiameter = 0;  // Stores the maximum diameter found

    int depth(TreeNode* root) {
        if (root == nullptr) return 0;  // Base case: Empty node has height 0
        
        int leftHeight = depth(root->left);  // Get height of left subtree
        int rightHeight = depth(root->right);  // Get height of right subtree
        
        // Update diameter: path through this node = leftHeight + rightHeight
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        
        return 1 + max(leftHeight, rightHeight);  // Return height of this node
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxDiameter;  // Return the maximum diameter found
    }
};

// Driver code to test the function
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of Binary Tree: " << sol.diameterOfBinaryTree(root) << endl;
    return 0;
}

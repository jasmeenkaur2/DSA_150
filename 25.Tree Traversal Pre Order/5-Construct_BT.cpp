#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor
};

class Solution {
public:
    unordered_map<int, int> inorderMap; // Stores index positions of inorder elements
    int preorderIndex = 0; // Keeps track of current root in preorder traversal

    // Main function to build tree from preorder and inorder arrays
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Step 1: Store inorder values and their indices in a hashmap for quick lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        // Step 2: Recursively build the tree
        return constructTree(preorder, 0, inorder.size() - 1);
    }

private:
    // Recursive function to construct the binary tree
    TreeNode* constructTree(vector<int>& preorder, int left, int right) {
        // Base case: If the left index is greater than the right, return NULL
        if (left > right) return nullptr;

        // Step 3: Get the current root node from preorder traversal
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Step 4: Find the index of this root in the inorder array
        int inorderIndex = inorderMap[rootValue];

        // Step 5: Recursively construct the left and right subtrees
        root->left = constructTree(preorder, left, inorderIndex - 1);
        root->right = constructTree(preorder, inorderIndex + 1, right);

        return root; // Return the root node
    }
};

// Helper function to print the inorder traversal of the constructed tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Driver code to test the solution
int main() {
    Solution solution;

    // Sample input:
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Build tree using the given preorder and inorder traversals
    TreeNode* root = solution.buildTree(preorder, inorder);

    // Print inorder traversal of the constructed tree to verify correctness
    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}

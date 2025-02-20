#include <iostream>
#include <vector>
#include <stack>
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
    // Function to check if a given tree is a valid BST
    bool isValidBST(TreeNode* root) {
        vector<int> inorder = inorderTraversal(root); // Get inorder sequence

        // Check if the inorder traversal is strictly increasing
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] <= inorder[i - 1]) {
                return false;  // Not a valid BST
            }
        }
        return true;  // Valid BST
    }

private:
    // Function to perform inorder traversal (Iterative)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;  // Stores the inorder sequence
        stack<TreeNode*> st; // Stack to store nodes
        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {
            // Push all left nodes onto the stack
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            // Process the top node
            current = st.top();
            st.pop();
            result.push_back(current->val); // Store value in the result

            // Move to the right subtree
            current = current->right;
        }

        return result; // Return the inorder traversal list
    }
};

// Function to test the BST validation
int main() {
    // Construct a BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;
    if (sol.isValidBST(root)) {
        cout << "The given tree is a valid BST." << endl;
    } else {
        cout << "The given tree is NOT a valid BST." << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;                // Value of the node
    TreeNode* left;         // Pointer to the left child
    TreeNode* right;        // Pointer to the right child

    // Constructor to initialize a new node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;  // Stores the final inorder sequence
        stack<TreeNode*> st; // Stack to keep track of nodes
        TreeNode* current = root; // Start traversal from root

        // Continue looping while there are nodes to process
        while (current != nullptr || !st.empty()) {

            // Step 1: Push all left nodes into the stack
            while (current != nullptr) {
                st.push(current);    // Store the current node
                current = current->left;  // Move to left child
            }

            // Step 2: Process the top node (Left is done, now process Root)
            current = st.top();  // Get the top node from the stack
            st.pop();            // Remove it from the stack
            result.push_back(current->val);  // Store its value in the result

            // Step 3: Move to the right subtree of the processed node
            current = current->right;
        }

        return result; // Return the inorder traversal result
    }
};

// Function to test the inorder traversal
int main() {
    // Constructing the following binary tree:
    //        4
    //       / \
    //      2   6
    //     / \  / \
    //    1   3 5  7

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<int> inorderResult = sol.inorderTraversal(root);

    // Print the inorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : inorderResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

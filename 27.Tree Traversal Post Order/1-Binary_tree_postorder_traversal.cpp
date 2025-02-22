#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;  // Stores the final postorder traversal sequence
        
        // If the tree is empty, return an empty vector
        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> st;  // Stack to simulate recursion
        TreeNode* curr = root;  // Pointer to traverse the tree
        TreeNode* lastVisited = nullptr;  // Tracks the last processed node

        while (!st.empty() || curr) {
            if (curr) {
                // Push the current node onto the stack and move left
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* topNode = st.top();  // Get the top node from the stack

                // If the right child exists and is not yet processed, move to the right
                if (topNode->right && lastVisited != topNode->right) {
                    curr = topNode->right;  // Move to right subtree
                } else {
                    // Process the node (add it to the result)
                    result.push_back(topNode->val);
                    lastVisited = topNode;  // Mark this node as processed
                    st.pop();  // Remove from stack
                }
            }
        }

        return result;  // Return the final postorder traversal sequence
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
    vector<int> result = sol.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : result) cout << val << " ";
    return 0;
}

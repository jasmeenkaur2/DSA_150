#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;               // Value of the node
    TreeNode* left;        // Pointer to the left child
    TreeNode* right;       // Pointer to the right child

    // Constructor to initialize a TreeNode
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class to implement the solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;  // To store the final level-order traversal
        if (!root) return result;   // If the tree is empty, return an empty vector

        queue<TreeNode*> q;         // Queue to perform BFS
        q.push(root);               // Start with the root node

        while (!q.empty()) {
            int levelSize = q.size();     // Number of nodes at the current level
            vector<int> currentLevel;    // To store the values of the nodes at the current level

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front(); // Get the front node in the queue
                q.pop();                    // Remove the processed node from the queue

                currentLevel.push_back(node->val); // Add the node's value to the current level

                // Add the node's children to the queue (if they exist)
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Add the current level to the final result
            result.push_back(currentLevel);
        }

        return result; // Return the final level-order traversal
    }
};

// Helper function to print the level-order traversal result
void printLevelOrder(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Main function to test the code
int main() {
    // Creating a sample binary tree
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create an instance of Solution and perform level-order traversal
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    // Print the result
    cout << "Level Order Traversal of the Binary Tree:" << endl;
    printLevelOrder(result);

    // Free allocated memory for the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

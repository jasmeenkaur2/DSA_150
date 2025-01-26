#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;               // Value of the node
    TreeNode* left;        // Pointer to the left child
    TreeNode* right;       // Pointer to the right child

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;  // To store the rightmost nodes of each level
        if (!root) return result;  // If the tree is empty, return an empty vector

        queue<TreeNode*> q;  // Queue to perform BFS
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // If this is the last node of the current level, add it to the result
                if (i == levelSize - 1) {
                    result.push_back(temp->val);
                }

                // Add left and right children to the queue (if they exist)
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return result;
    }
};

// Helper function to print the right side view
void printRightSideView(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function to test the code
int main() {
    // Creating a sample binary tree
    /*
            1
          /   \
         2     3
        / \      \
       4   5      6
            \
             7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    // Create an instance of Solution and compute the right side view
    Solution solution;
    vector<int> result = solution.rightSideView(root);

    // Print the result
    cout << "Right Side View of the Binary Tree:" << endl;
    printRightSideView(result);

    // Free allocated memory for the tree nodes
    delete root->left->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

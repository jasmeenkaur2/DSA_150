#include <iostream>
#include <queue>
using namespace std;

// Definition of the TreeNode structure
struct TreeNode {
    int val;                 // Value of the node
    TreeNode* left;          // Pointer to the left child
    TreeNode* right;         // Pointer to the right child

    // Constructor to initialize a node
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to check if the tree is symmetric
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;  // An empty tree is symmetric

        queue<TreeNode*> q;  // Queue to store nodes in pairs
        q.push(root->left);  // Push left child of root
        q.push(root->right); // Push right child of root

        // While there are nodes to process in the queue
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();  // Get the left node
            TreeNode* right = q.front(); q.pop(); // Get the right node

            // Case 1: Both nodes are null, continue checking the next pair
            if (!left && !right) continue;

            // Case 2: One node is null and the other isn't, return false (not symmetric)
            if (!left || !right || left->val != right->val) return false;

            // Case 3: Nodes are equal, so add their children in mirrored order
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }

        return true;  // If no mismatches, tree is symmetric
    }
};

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    /*
       Tree structure:
             1
            / \
           2   2
          / \ / \
         3  4 4  3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    return root;
}

int main() {
    Solution solution;

    // Create the sample tree
    TreeNode* root = createSampleTree();

    // Check if the tree is symmetric
    bool result = solution.isSymmetric(root);

    // Print the result
    if (result) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}

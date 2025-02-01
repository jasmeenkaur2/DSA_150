#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;                 // Node value
    TreeNode* left;           // Pointer to the left child
    TreeNode* right;          // Pointer to the right child

    // Constructor for convenience
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Preorder traversal: Root → Left → Right using a stack
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;  // To store the traversal result

        if (!root) return result;  // Edge case: empty tree

        stack<TreeNode*> s1;  // Stack to keep track of nodes
        s1.push(root);        // Push the root node to start traversal

        while (!s1.empty()) {
            // Visit the top node
            TreeNode* temp = s1.top();
            result.push_back(temp->val);
            s1.pop();  // Remove the node after processing

            // Push right child first so that left is processed first
            if (temp->right) s1.push(temp->right);
            if (temp->left) s1.push(temp->left);
        }

        return result;
    }
};

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    /*
       Tree structure:
             1
            / \
           2   3
          / \
         4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return root;
}

int main() {
    Solution solution;

    // Create the sample tree
    TreeNode* root = createSampleTree();

    // Get preorder traversal result
    vector<int> preorderResult = solution.preorderTraversal(root);

    // Print the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : preorderResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

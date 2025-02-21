#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st; // Stack to store nodes for inorder traversal

    // Helper function to push all left children of a node onto the stack
    void pushLeftNodes(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;  // Move to the left child
        }
    }

public:
    // Constructor: Initialize iterator by storing leftmost path in stack
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
    }

    // Returns the next smallest element in BST (Inorder traversal)
    int next() {
        TreeNode* topNode = st.top();  // Get the top node (smallest available)
        st.pop();  // Remove it from stack

        // If the node has a right subtree, push all its left children
        if (topNode->right) {
            pushLeftNodes(topNode->right);
        }

        return topNode->val; // Return the smallest element
    }

    // Returns true if there are more elements left in BST
    bool hasNext() {
        return !st.empty(); // Stack not empty means elements are left
    }
};

// Function to test BSTIterator
int main() {
    // Constructing the BST:
    //        7
    //       / \
    //      3   15
    //         /  \
    //        9   20

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Initialize the iterator
    BSTIterator iterator(root);

    // Print all elements in sorted order using iterator
    cout << "Inorder Traversal using BST Iterator: ";
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    
    // Expected Output: 3 7 9 15 20
    return 0;
}

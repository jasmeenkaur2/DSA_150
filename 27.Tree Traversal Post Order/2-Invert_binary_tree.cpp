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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;  // Base case: If tree is empty, return nullptr
        }

        stack<TreeNode*> st;
        st.push(root);  // Push root onto the stack

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            // Swap left and right children
            swap(curr->left, curr->right);

            // Push non-null children onto the stack
            if (curr->left) st.push(curr->left);
            if (curr->right) st.push(curr->right);
        }

        return root;  // Return the inverted tree
    }
};

// Driver code to test the function
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << "Original Inorder: ";
    printInorder(root);
    cout << endl;

    TreeNode* invertedRoot = sol.invertTree(root);

    cout << "Inverted Inorder: ";
    printInorder(invertedRoot);
    cout << endl;

    return 0;
}

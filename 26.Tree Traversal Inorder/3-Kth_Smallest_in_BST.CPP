#include <iostream>
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* current = root;
        int count = 0;  // Track the number of elements processed

        while (current != nullptr || !st.empty()) {
            // Push all left nodes onto the stack
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            // Process the smallest node (leftmost in BST)
            current = st.top();
            st.pop();
            count++;

            // If we found the kth smallest, return it
            if (count == k) return current->val;

            // Move to the right subtree
            current = current->right;
        }

        return -1; // Should not reach here for valid k
    }
};

// Function to test the kth smallest element retrieval
int main() {
    // Constructing the BST:
    //        5
    //       / \
    //      3   7
    //     / \  / \
    //    2   4 6  8

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;
    int k = 3;
    cout << "The " << k << "rd smallest element is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}

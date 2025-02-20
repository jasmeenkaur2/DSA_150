#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor
};

class Solution {
public:
    // Function to convert sorted array to height-balanced BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    // Helper function to recursively build BST
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // Base case: if left index exceeds right, return nullptr
        if (left > right) return nullptr;
        
        // Select middle element as root to ensure balance
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively construct left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
        return root;
    }
};

// Utility function to print tree in-order (for testing)
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver code to test the function
int main() {
    Solution solution;
    vector<int> nums = { -10, -3, 0, 5, 9 };

    TreeNode* root = solution.sortedArrayToBST(nums);

    // Print the BST in-order (should print sorted numbers)
    cout << "In-order Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

#include <iostream>
#include <climits>
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
    int maxSum = INT_MIN;  // Stores the maximum path sum

    int findMaxPath(TreeNode* root) {
        if (root == nullptr) return 0;  // Base case: Empty node returns 0

        // Recursively get max sum from left and right (Ignore negative sums)
        int leftMax = max(0, findMaxPath(root->left));
        int rightMax = max(0, findMaxPath(root->right));

        // Compute the max sum at this node (including both left and right)
        int splitPathSum = root->val + leftMax + rightMax;

        // Update global max sum if this path is better
        maxSum = max(maxSum, splitPathSum);

        // Return max single path sum (to be used in recursion)
        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        findMaxPath(root);
        return maxSum;  // Return the maximum path sum found
    }
};

// Driver Code
int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;  // Output: 42

    return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;

// Definition of TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSum;
        prefixSum[0] = 1;  // Base case: A sum of 0 exists once
        return dfs(root, 0, targetSum, prefixSum);
    }

private:
    int dfs(TreeNode* node, long currentSum, int targetSum, unordered_map<long, int>& prefixSum) {
        if (!node) return 0;

        currentSum += node->val;  // Update running sum

        int count = prefixSum[currentSum - targetSum]; // Check if any valid path exists

        prefixSum[currentSum]++; // Add current sum to the hash map

        // Recur to left and right children
        count += dfs(node->left, currentSum, targetSum, prefixSum);
        count += dfs(node->right, currentSum, targetSum, prefixSum);

        prefixSum[currentSum]--; // 🔥 Remove current sum (Backtrack)

        return count;
    }
};

// Driver function to test the code
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 8;
    cout << "Number of paths: " << sol.pathSum(root, targetSum) << endl;

    return 0;
}
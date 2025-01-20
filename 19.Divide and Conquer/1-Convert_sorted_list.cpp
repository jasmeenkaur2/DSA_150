#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr; // Base case: Empty list
        if (!head->next) return new TreeNode(head->val); // Base case: Single node

        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the left half from the middle
        if (prev) prev->next = nullptr;

        // Middle element is the root
        TreeNode* root = new TreeNode(slow->val);

        // Recursively build left and right subtrees
        root->left = sortedListToBST(head); // Left half
        root->right = sortedListToBST(slow->next); // Right half

        return root;
    }
};

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            // Nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
        }

        return dummy->next;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    Solution solution;
    ListNode* result = solution.swapPairs(head);

    printList(result); // Output: 2 1 4 3
    return 0;
}

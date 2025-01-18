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
    ListNode* middleNode(ListNode* head) {
        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list, moving slow by 1 step and fast by 2 steps
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Move slow pointer by 1 step
            fast = fast->next->next;  // Move fast pointer by 2 steps
        }

        // Slow pointer will be at the middle of the list when fast reaches the end
        return slow;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code to test the solution
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* middle = solution.middleNode(head);

    cout << "Middle Node Value: " << middle->val << endl; // Output: 3
    return 0;
}

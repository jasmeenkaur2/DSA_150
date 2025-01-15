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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases such as removing the head node.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize two pointers, both starting from the dummy node.
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move the 'first' pointer n+1 steps ahead to maintain a gap of n between 'first' and 'second'.
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Move both 'first' and 'second' pointers one step at a time until 'first' reaches the end.
        // At this point, 'second' will be just before the node to be removed.
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the target node by skipping it in the list.
        ListNode* target = second->next; // The node to be deleted.
        second->next = second->next->next; // Update the link to bypass the target node.
        delete target; // Free the memory of the removed node.

        // Update the head pointer to the new list starting from the node after dummy.
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node's memory.
        return newHead; // Return the updated head of the list.
    }
};

// Helper function to print a linked list.
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

// Helper function to create a linked list from an array of values.
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Main function for testing the code.
int main() {
    // Create a test linked list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    cout << "Original List: ";
    printList(head);

    // Remove the 2nd node from the end.
    Solution solution;
    int n = 2;
    head = solution.removeNthFromEnd(head, n);

    cout << "Updated List after removing " << n << "th node from the end: ";
    printList(head);

    // Clean up memory.
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

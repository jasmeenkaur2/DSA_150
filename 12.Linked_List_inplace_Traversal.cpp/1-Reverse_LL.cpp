#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val; // Value of the node
    ListNode* next; // Pointer to the next node

    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // Initialize previous pointer
        ListNode* current = head; // Start with the head node

        while (current != nullptr) {
            ListNode* next = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current; // Move prev to the current node
            current = next; // Move current to the next node
        }

        return prev; // Prev becomes the new head
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " "; // Print the value of the current node
        head = head->next; // Move to the next node
    }
    cout << endl;
}

// Driver code
int main() {
    // Create linked list: [1, 2, 3, 4, 5]
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    printList(reversedHead); // Output: 5 4 3 2 1
    return 0;
}

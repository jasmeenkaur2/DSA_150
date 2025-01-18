#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val; // Value of the node
    ListNode* next; // Pointer to the next node

    // Default constructor
    ListNode() : val(0), next(nullptr) {}

    // Constructor to initialize the node with a value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor to initialize the node with a value and a pointer to the next node
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to add two numbers represented as linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify result list manipulation
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy; // Pointer to build the result list
        int carry = 0; // Carry for addition

        // Loop until both lists are fully traversed and there is no carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry

            // Add the value from the first list if it exists
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; // Move to the next node in l1
            }

            // Add the value from the second list if it exists
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; // Move to the next node in l2
            }

            carry = sum / 10; // Update carry for the next iteration
            current->next = new ListNode(sum % 10); // Create a new node with the remainder
            current = current->next; // Move the pointer in the result list
        }

        return dummy->next; // Return the result list (skip dummy node)
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
    // Create linked lists: l1 = [2, 4, 3], l2 = [5, 6, 4]
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    printList(result); // Output: 7 0 8
    return 0;
}

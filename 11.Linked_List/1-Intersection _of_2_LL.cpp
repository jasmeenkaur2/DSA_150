#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;                 // Value of the node
    ListNode* next;          // Pointer to the next node
    ListNode() : val(0), next(nullptr) {} // Default constructor
    ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
    ListNode(int x, ListNode* next) : val(x), next(next) {} // Constructor with value and next node
};

class Solution {
public:
    // Function to find the intersection node of two linked lists
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // If either of the lists is empty, there is no intersection
        if (!headA || !headB) return nullptr;

        // Initialize two pointers, one for each list
        ListNode* pA = headA;
        ListNode* pB = headB;

        // Traverse the lists
        while (pA != pB) { // Loop until the pointers meet (or both become nullptr)
            // If pA reaches the end of list A, redirect it to the start of list B
            pA = (pA == nullptr) ? headB : pA->next;

            // If pB reaches the end of list B, redirect it to the start of list A
            pB = (pB == nullptr) ? headA : pB->next;
        }

        // Either both pointers meet at the intersection node, or both are nullptr (no intersection)
        return pA;
    }
};

// Helper function to create a linked list from a vector of values
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr; // Empty list case

    ListNode* head = new ListNode(values[0]); // Create the head node
    ListNode* current = head; // Pointer to track the current node

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]); // Create a new node and link it
        current = current->next; // Move to the new node
    }

    return head; // Return the head of the created list
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Main function to test the solution
int main() {
    // Create two linked lists with an intersection
    ListNode* intersect = new ListNode(8, new ListNode(4, new ListNode(5))); // Common intersection part

    ListNode* headA = new ListNode(4, new ListNode(1, intersect)); // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5, new ListNode(6, new ListNode(1, intersect))); // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5

    // Print the two lists
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    // Find the intersection node
    Solution solution;
    ListNode* result = solution.getIntersectionNode(headA, headB);

    // Output the result
    if (result) {
        cout << "Intersected at '" << result->val << "'" << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}

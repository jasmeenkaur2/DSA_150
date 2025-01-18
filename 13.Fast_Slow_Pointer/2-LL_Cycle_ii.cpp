#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if a cycle exists
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, a cycle exists
            if (slow == fast) {
                // Step 2: Find the start of the cycle
                ListNode* entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry; // Start of the cycle
            }
        }

        return nullptr; // No cycle
    }
};

// Helper function to create a cycle in the linked list
ListNode* createCycleList() {
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // Cycle starts at node1

    return head;
}

// Driver code
int main() {
    ListNode* head = createCycleList();
    Solution solution;
    ListNode* cycleStart = solution.detectCycle(head);

    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}

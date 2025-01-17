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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Step 2: Optimize k
        k %= n;
        if (k == 0) return head; // No rotation needed

        // Step 3: Form a circular list
        tail->next = head;

        // Step 4: Find the new tail (n - k steps from the beginning)
        int stepsToNewTail = n - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 5: Break the circular list
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    Solution solution;
    ListNode* result = solution.rotateRight(head, 2);

    printList(result); // Output: 4 5 1 2 3
    return 0;
}

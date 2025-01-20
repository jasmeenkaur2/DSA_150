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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify the merge process
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Merge the two lists
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1; // Add list1's node to the merged list
                list1 = list1->next;
            } else {
                tail->next = list2; // Add list2's node to the merged list
                list2 = list2->next;
            }
            tail = tail->next; // Move the tail forward
        }

        // Append the remaining nodes of the non-empty list
        tail->next = list1 ? list1 : list2;

        // Return the merged list, skipping the dummy node
        return dummy->next;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two sorted linked lists
    vector<int> values1 = {1, 2, 4};
    vector<int> values2 = {1, 3, 4};

    ListNode* list1 = createLinkedList(values1);
    ListNode* list2 = createLinkedList(values2);

    // Print the input lists
    cout << "List 1: ";
    printLinkedList(list1);
    cout << "List 2: ";
    printLinkedList(list2);

    // Merge the two lists
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    printLinkedList(mergedList);

    return 0;
}

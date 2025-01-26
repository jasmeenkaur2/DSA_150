#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr; // If the tree is empty, return nullptr

        Node* current = root; // Start at the root of the tree

        while (current) {
            Node* dummy = new Node(0); // Dummy node to start the next level
            Node* tail = dummy;        // Tail pointer to connect nodes at the next level

            while (current) {
                // Connect the left child if it exists
                if (current->left) {
                    tail->next = current->left;
                    tail = tail->next;
                }

                // Connect the right child if it exists
                if (current->right) {
                    tail->next = current->right;
                    tail = tail->next;
                }

                // Move to the next node in the current level
                current = current->next;
            }

            // Move to the next level
            current = dummy->next;

            // Free the dummy node (optional since we're working with a constant space constraint)
            delete dummy;
        }

        return root; // Return the modified root
    }
};

// Helper function to print the tree level-by-level using next pointers
void printTree(Node* root) {
    Node* levelStart = root;

    while (levelStart) {
        Node* current = levelStart;
        levelStart = nullptr;

        while (current) {
            cout << current->val << " ";
            if (!levelStart) {
                if (current->left) levelStart = current->left;
                else if (current->right) levelStart = current->right;
            }
            current = current->next;
        }

        cout << "#" << endl; // End of level
    }
}

// Main function to test the solution
int main() {
    // Create a sample binary tree
    /*
            1
          /   \
         2     3
        / \      \
       4   5      7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    // Connect next pointers
    Solution solution;
    solution.connect(root);

    // Print the tree level-by-level using next pointers
    cout << "Tree after populating next pointers:" << endl;
    printTree(root);

    // Free allocated memory for the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

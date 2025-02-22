#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // HashMap for dynamic character storage
    bool isEnd; // Marks if a word ends at this node

    TrieNode() {
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode(); // Initialize root node
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            // If character doesn't exist, create a new node
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch]; // Move to the next node
        }
        curr->isEnd = true; // Mark end of word
    }

    // Search for a complete word in the Trie
    bool search(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false; // Character path doesn't exist
            }
            curr = curr->children[ch]; // Move to next node
        }
        return curr->isEnd; // Word must end at this node
    }

    // Check if any word in the Trie starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false; // Prefix doesn't exist
            }
            curr = curr->children[ch]; // Move to next node
        }
        return true; // If we reached here, prefix exists
    }
};

// Driver code to test Trie
int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // true (1)
    cout << trie.search("app") << endl;     // false (0)
    cout << trie.startsWith("app") << endl; // true (1)
    trie.insert("app");
    cout << trie.search("app") << endl;     // true (1)

    return 0;
}

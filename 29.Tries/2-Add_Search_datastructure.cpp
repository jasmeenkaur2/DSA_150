#include <iostream>
#include <unordered_map>
using namespace std;

class WordDictionary {
private:
    // Define a TrieNode structure
    struct TrieNode {
        unordered_map<char, TrieNode*> children; // Hash map to store child nodes dynamically
        bool isEnd = false; // Indicates if a word ends at this node
    };

    TrieNode* root; // Root node of the Trie

public:
    /** Constructor: Initializes the Trie */
    WordDictionary() {
        root = new TrieNode(); // Create an empty root node
    }
    
    /** Adds a word to the dictionary (Trie) */
    void addWord(string word) {
        TrieNode* current = root; // Start from the root node
        for (char c : word) {
            int index = c - 'a'; // Convert char to index (0-25)

            // If there is no TrieNode for this letter, create one
            if (!current->children[c]) {
                current->children[c] = new TrieNode();
            }
            
            // Move to the next TrieNode
            current = current->children[c];
        }
        
        // Mark the last node as the end of a valid word
        current->isEnd = true;
    }
    
    /** Helper function to recursively search for a word, supporting `.` wildcard */
    bool searchHelper(TrieNode* node, string& word, int index) {
        // Base case: If node is NULL, return false
        if (!node) return false;

        // If we have checked all letters, return true only if `isEnd` is true
        if (index == word.size()) return node->isEnd;

        char c = word[index]; // Get the current character

        // Case 1: If the character is '.', check all possible children
        if (c == '.') {
            for (auto& child : node->children) {
                if (searchHelper(child.second, word, index + 1)) {
                    return true; // If any path is valid, return true
                }
            }
            return false; // No valid path found
        }
        // Case 2: Normal letter lookup
        else {
            if (!node->children.count(c)) return false; // Letter not found in Trie
            return searchHelper(node->children[c], word, index + 1); // Move to the next character
        }
    }

    /** Public search function to check if a word exists */
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};

/** Driver class to test the WordDictionary */
int main() {
    WordDictionary wd;

    // Adding words to the Trie
    wd.addWord("bad");
    wd.addWord("bat");
    wd.addWord("cat");

    // Searching for exact words
    cout << "Search 'bad': " << (wd.search("bad") ? "true" : "false") << endl;  // true
    cout << "Search 'bat': " << (wd.search("bat") ? "true" : "false") << endl;  // true
    cout << "Search 'cat': " << (wd.search("cat") ? "true" : "false") << endl;  // true
    cout << "Search 'dog': " << (wd.search("dog") ? "true" : "false") << endl;  // false

    // Searching with wildcards
    cout << "Search 'b..': " << (wd.search("b..") ? "true" : "false") << endl;  // true (matches "bad" or "bat")
    cout << "Search 'ba.': " << (wd.search("ba.") ? "true" : "false") << endl;  // true (matches "bad" or "bat")
    cout << "Search 'c.t': " << (wd.search("c.t") ? "true" : "false") << endl;  // true (matches "cat")
    cout << "Search '.a.': " << (wd.search(".a.") ? "true" : "false") << endl;  // true (matches "bad", "bat", "cat")

    return 0;
}

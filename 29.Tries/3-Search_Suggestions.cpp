#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/** TrieNode Class: Represents each node in the Trie */
class TrieNode {
public:
    TrieNode* children[26] = {}; // Array of 26 pointers (for a-z)
    vector<string> suggestions;  // Stores up to 3 lexicographically smallest words
};

/** Trie Class: Implements insert and search functionality */
class Trie {
private:
    TrieNode* root; // Root node of Trie

public:
    /** Constructor */
    Trie() {
        root = new TrieNode(); // Initialize root node
    }

    /** Insert a word into the Trie */
    void insert(string word) {
        TrieNode* node = root; // Start from the root

        for (char c : word) {
            int index = c - 'a'; // Convert character to index (0-25)

            // If there is no TrieNode for this letter, create one
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }

            // Move to the next node
            node = node->children[index];

            // Store up to 3 lexicographically smallest words
            if (node->suggestions.size() < 3) {
                node->suggestions.push_back(word);
            }
        }
    }

    /** Get product suggestions for a given prefix */
    vector<vector<string>> getSuggestions(string searchWord) {
        vector<vector<string>> result;
        TrieNode* node = root;

        for (char c : searchWord) {
            int index = c - 'a';

            // If there is no matching child node, return empty lists for remaining characters
            if (!node->children[index]) {
                while (result.size() < searchWord.size()) {
                    result.push_back({});
                }
                return result;
            }

            // Move to the next node
            node = node->children[index];

            // Store the suggestions for this prefix
            result.push_back(node->suggestions);
        }

        return result;
    }
};

/** Solution Class: Implements the main logic */
class Solution {
public:
    /** Function to return search suggestions */
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); // Sort products lexicographically
        Trie trie;

        // Insert all products into the Trie
        for (string& product : products) {
            trie.insert(product);
        }

        // Get suggestions for each prefix of searchWord
        return trie.getSuggestions(searchWord);
    }
};

/** Driver Code to Test the Implementation */
int main() {
    Solution sol;
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";

    vector<vector<string>> result = sol.suggestedProducts(products, searchWord);

    // Print result
    for (int i = 0; i < result.size(); i++) {
        cout << "Prefix '" << searchWord.substr(0, i + 1) << "': ";
        for (string& word : result[i]) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

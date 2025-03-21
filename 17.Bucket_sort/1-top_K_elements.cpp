#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freqMap;

    // Step 1: Count word frequencies
    for (string& word : words) {
        freqMap[word]++;
    }

    int n = words.size();
    vector<vector<string>> buckets(n + 1); // Buckets from 0 to n

    // Step 2: Place words into corresponding frequency bucket
    for (auto& entry : freqMap) {
        buckets[entry.second].push_back(entry.first);
    }

    // Step 3: Collect k most frequent words
    vector<string> result;
    for (int i = n; i >= 0; --i) {  // Start from highest frequency
        if (!buckets[i].empty()) {
            // Step 4: Sort bucket lexicographically
            sort(buckets[i].begin(), buckets[i].end());
            for (string& word : buckets[i]) {
                result.push_back(word);
                if (result.size() == k) return result;
            }
        }
    }

    return result;
}

// Driver code
int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    
    vector<string> result = topKFrequent(words, k);
    cout << "Top " << k << " frequent words: ";
    for (string& word : result) {
        cout << word << " ";
    }

    return 0;
}

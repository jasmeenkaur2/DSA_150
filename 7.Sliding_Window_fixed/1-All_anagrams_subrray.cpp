#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result; // Stores the starting indices of all anagrams found
        
        // If p is longer than s, no anagram is possible
        if (p.size() > s.size()) {
            return result;
        }
        
        vector<int> P_Freq(26, 0), S_Freq(26, 0); // Frequency arrays for p and the sliding window in s

        // Populate the frequency array for the characters in p
        for (char c : p) {
            P_Freq[c - 'a']++;
        }

        int left = 0, right = 0; // Two pointers for the sliding window

        // Expand the sliding window across s
        while (right < s.size()) {
            // Add the current character to the sliding window frequency
            S_Freq[s[right] - 'a']++;
            right++; // Move the right pointer to expand the window

            // If the window size exceeds the size of p, shrink it from the left
            if (right - left > p.size()) {
                S_Freq[s[left] - 'a']--; // Remove the leftmost character from the window frequency
                left++; // Move the left pointer to shrink the window
            }

            // If the frequency of the current window matches p's frequency, it is an anagram
            if (S_Freq == P_Freq) {
                result.push_back(left); // Add the starting index of the anagram to the result
            }
        }

        return result; // Return the list of starting indices of anagrams
    }
};

int main()
{
 return 0;
}
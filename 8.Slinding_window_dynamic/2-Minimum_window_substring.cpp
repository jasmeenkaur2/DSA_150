#include<iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return ""; // Edge case: if either string is empty.

        // Frequency map for characters in t.
        unordered_map<char, int> charCount;
        for (char c : t) {
            charCount[c]++;
        }

        int required = charCount.size(); // Number of unique characters in t.
        int l = 0, r = 0; // Left and right pointers of the sliding window.
        int formed = 0; // Number of characters that match the frequency in t.

        // Frequency map for characters in the current window.
        unordered_map<char, int> windowCount;

        // Variables to store the result.
        int minLength = INT_MAX;
        int start = 0;

        // Expand the window by moving the right pointer.
        while (r < s.size()) {
            char c = s[r];
            windowCount[c]++;

            // If the current character's frequency matches its frequency in t.
            if (charCount.find(c) != charCount.end() && windowCount[c] == charCount[c]) {
                formed++;
            }

            // Try to contract the window until it becomes invalid.
            while (l <= r && formed == required) {
                c = s[l];

                // Update the result if this window is smaller than the previous best.
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    start = l;
                }

                // Shrink the window.
                windowCount[c]--;
                if (charCount.find(c) != charCount.end() && windowCount[c] < charCount[c]) {
                    formed--;
                }

                l++; // Move the left pointer forward.
            }

            r++; // Move the right pointer forward.
        }

        // Return the smallest window or an empty string if no valid window exists.
        return (minLength == INT_MAX) ? "" : s.substr(start, minLength);
    }
};

int main()
{
 return 0;
}
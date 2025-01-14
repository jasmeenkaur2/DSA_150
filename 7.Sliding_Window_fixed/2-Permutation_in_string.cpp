#include<iostream>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // If s1 is longer than s2, s1 cannot be a permutation of any substring of s2
        if (s2.size() < s1.size()) {
            return false;
        }

        vector<int> s1_freq(26, 0), s2_freq(26, 0); // Frequency arrays for s1 and the current window in s2
        int left = 0, right = 0; // Sliding window pointers

        // Populate the frequency array for s1
        for (char c : s1) {
            s1_freq[c - 'a']++;
        }

        // Expand the sliding window across s2
        while (right < s2.size()) {
            s2_freq[s2[right] - 'a']++; // Add the current character to the window
            right++; // Move the right pointer to expand the window

            // Shrink the window if it exceeds the size of s1
            if (right - left > s1.size()) {
                s2_freq[s2[left] - 'a']--; // Remove the leftmost character
                left++; // Move the left pointer to shrink the window
            }

            // If the frequency of the current window matches s1's frequency, return true
            if (s1_freq == s2_freq) {
                return true;
            }
        }

        // No permutation of s1 found in s2
        return false;
    }
};

int main()
{
 return 0;
}
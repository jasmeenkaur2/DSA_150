#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last index of each character
        unordered_map<char, int> lastIndex;
        int maxlength = 0;  // Tracks the length of the longest substring
        int left = 0;       // Left pointer of the sliding window

        // Iterate through the string with the right pointer
        for (int right = 0; right < s.size(); right++) {
            // If the character is already in the window (seen before)
            if (lastIndex.find(s[right]) != lastIndex.end() && lastIndex[s[right]] >= left) {
                // Move the left pointer to exclude the previous occurrence of s[right]
                left = lastIndex[s[right]] + 1;
            }

            // Update the last index of the current character
            lastIndex[s[right]] = right;

            // Calculate the current window length and update the maximum length
            maxlength = max(maxlength, right - left + 1);
        }

        return maxlength;
    }
};

int main()
{
 return 0;
}
#include<iostream>
using namespace std;
class Solution {
public:
    // This function partitions the string `s` such that every substring in each partition is a palindrome.
    // It returns all possible palindrome partitions as a vector of vector of strings.
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result; // To store the final result of all palindrome partitions.
        vector<string> currentPartition; // To store the current partition being explored.
        backtrack(s, 0, currentPartition, result); // Start the backtracking process from index 0.
        return result; // Return the result after exploring all partitions.
    }

private:
    // Backtracking function to explore all possible palindrome partitions.
    void backtrack(string &s, int start, vector<string> &currentPartition, vector<vector<string>> &result) {
        // Base case: If `start` reaches the end of the string, add the current partition to the result.
        if (start == s.length()) {
            result.push_back(currentPartition);
            return;
        }

        // Loop to explore all substrings starting from the current index `start`.
        for (int end = start; end < s.length(); ++end) {
            // Check if the substring from `start` to `end` is a palindrome.
            if (isPalindrome(s, start, end)) {
                // If it is a palindrome, add the substring to the current partition.
                currentPartition.push_back(s.substr(start, end - start + 1));
                // Recursively explore further partitions starting from `end + 1`.
                backtrack(s, end + 1, currentPartition, result);
                // Backtrack: Remove the last added substring to explore other possibilities.
                currentPartition.pop_back();
            }
        }
    }

    // Helper function to check if a substring of `s` from `left` to `right` is a palindrome.
    bool isPalindrome(string &s, int left, int right) {
        // Compare characters from the beginning (`left`) and end (`right`) of the substring.
        while (left < right) {
            // If characters at `left` and `right` are not equal, it's not a palindrome.
            if (s[left] != s[right]) return false;
            ++left;  // Move the left pointer inward.
            --right; // Move the right pointer inward.
        }
        // If all characters match, the substring is a palindrome.
        return true;
    }
};

int main()
{
 return 0;
}
#include<iostream>
using namespace std;

class Solution {
public:
    // Helper function for backtracking
    void Backtracking(string current, int open, int close, int max, vector<string>& result) {
        // Base case: If the current string has reached the required length (2 * max),
        // it means we have a valid combination of parentheses. Add it to the result.
        if (current.length() == max * 2) {
            result.push_back(current); // Store the valid combination
            return; // Exit the current recursive call
        }

        // If the number of open parentheses used is less than max, we can add an open parenthesis '('.
        if (open < max) {
            // Add an open parenthesis and recurse further with incremented open count.
            Backtracking(current + "(", open + 1, close, max, result);
        }

        // If the number of close parentheses used is less than the number of open parentheses,
        // we can add a close parenthesis ')' to maintain validity.
        if (close < open) {
            // Add a close parenthesis and recurse further with incremented close count.
            Backtracking(current + ")", open, close + 1, max, result);
        }
    }

    // Main function to generate all combinations of valid parentheses
    vector<string> generateParenthesis(int n) {
        vector<string> result; // This will store all the valid combinations
        Backtracking("", 0, 0, n, result); // Start backtracking with an empty string and counts at 0
        return result; // Return the final list of combinations
    }
};

int main()
{
 return 0;
}
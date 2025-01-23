#include<iostream>
using namespace std;
class Solution {
public:
    // Helper function to perform backtracking
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        // Base case: If the current permutation is complete
        if (current.size() == nums.size()) {
            result.push_back(current); // Add it to the result
            return;
        }

        // Iterate through all numbers in the array
        for (int i = 0; i < nums.size(); ++i) {
            // Skip the number if it is already used
            if (used[i]) continue;

            // Include the number in the current permutation
            current.push_back(nums[i]);
            used[i] = true; // Mark the number as used

            // Recurse to generate permutations for the remaining numbers
            backtrack(nums, used, current, result);

            // Backtrack: Undo the choice for the next iteration
            current.pop_back();
            used[i] = false; // Mark the number as unused
        }
    }

    // Main function to generate all permutations
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; // Store all permutations
        vector<int> current; // Current permutation being built
        vector<bool> used(nums.size(), false); // Track used numbers

        // Start backtracking
        backtrack(nums, used, current, result);

        return result;
    }
};

int main()
{
 return 0;
}
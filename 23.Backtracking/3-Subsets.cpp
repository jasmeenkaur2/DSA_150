#include<iostream>
using namespace std;
class Solution {
public:
    // Backtracking helper function
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);

        // Iterate through the remaining elements
        for (int i = start; i < nums.size(); ++i) {
            // Include the current element
            current.push_back(nums[i]);

            // Recur to generate subsets with the current element
            backtrack(nums, i + 1, current, result);

            // Backtrack: Remove the current element to explore other subsets
            current.pop_back();
        }
    }

    // Main function to generate all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; // Store all subsets
        vector<int> current;        // Current subset being built

        // Start backtracking
        backtrack(nums, 0, current, result);

        return result;
    }
};
int main()
{
 return 0;
}
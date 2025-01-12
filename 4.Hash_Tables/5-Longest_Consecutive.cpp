#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    // Function to find the length of the longest consecutive sequence
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Insert all numbers into an unordered set
        // This allows for O(1) average time complexity for lookups
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longestStreak = 0; // Variable to store the length of the longest consecutive sequence

        // Step 2: Iterate over each number in the set
        for (int num : numSet) {
            // Step 3: Check if the current number is the start of a sequence
            // If `num - 1` exists in the set, `num` is not the start of a sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;       // Start the sequence with the current number
                int currentStreak = 1;      // Initialize the streak length to 1

                // Step 4: Check how far the sequence can go
                // Increment the current number and streak length as long as the next number exists
                while (numSet.count(currentNum + 1)) {
                    currentNum += 1;        // Move to the next number in the sequence
                    currentStreak += 1;    // Increase the streak length
                }

                // Step 5: Update the longest streak found so far
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        // Step 6: Return the length of the longest consecutive sequence
        return longestStreak;
    }
};

int main()
{
 return 0;
}
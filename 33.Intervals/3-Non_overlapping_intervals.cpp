#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals based on the ending time (Greedy approach)
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; // Sort by end time
        });

        int count = 0; // Number of intervals to remove
        int prevEnd = intervals[0][1]; // Store end time of the last added interval

        // Step 2: Iterate through intervals (start from the 2nd interval)
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval starts before the previous one ends, it overlaps
            if (intervals[i][0] < prevEnd) {
                count++; // Remove this interval
            } else {
                prevEnd = intervals[i][1]; // Update previous end time
            }
        }
        return count; // Return minimum number of intervals to remove
    }
};

// Driver Code
int main() {
    Solution solution;

    // Sample Input: [[1,2], [2,3], [3,4], [1,3]]
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};

    // Compute result
    int result = solution.eraseOverlapIntervals(intervals);

    // Print Output
    cout << "Minimum number of intervals to remove: " << result << endl;

    return 0;
}

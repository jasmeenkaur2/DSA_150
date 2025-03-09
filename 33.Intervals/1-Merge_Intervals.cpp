#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // If there are no intervals, return an empty list
    if (intervals.empty()) return {};
    
    // Step 1: Sort intervals based on the start time
    sort(intervals.begin(), intervals.end()); 
    
    vector<vector<int>> merged; // Result vector to store merged intervals

    // Step 2: Iterate through each interval
    for (auto& interval : intervals) {
        // If merged is empty OR the current interval does not overlap with the last merged interval
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval); // Directly add it as a new interval
        } else {
            // If overlapping, merge by updating the end time of the last interval in merged
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged; // Return the merged intervals
}

// Driver code to test the function
int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    
    // Call the merge function
    vector<vector<int>> result = merge(intervals);
    
    // Print the merged intervals
    cout << "Merged Intervals: ";
    for (auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}

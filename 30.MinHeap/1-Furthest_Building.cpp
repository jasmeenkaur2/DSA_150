#include <iostream>
#include <vector>
#include <queue>  // For priority_queue (Min-Heap)
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // Min-heap (priority queue) to store the heights we have climbed using ladders
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Traverse all buildings except the last one
        for (int i = 0; i < heights.size() - 1; i++) {
            // Calculate the height difference to the next building
            int diff = heights[i + 1] - heights[i];

            // If the next building is taller, we need to climb
            if (diff > 0) {
                minHeap.push(diff);  // Add the jump height to the min-heap
                
                // If we have used more ladders than available, convert the smallest ladder use to bricks
                if (minHeap.size() > ladders) {
                    bricks -= minHeap.top(); // Convert the smallest jump (stored in minHeap) to bricks
                    minHeap.pop(); // Remove that jump from the heap as it is now covered by bricks
                }

                // If bricks go negative, we cannot move further
                if (bricks < 0) {
                    return i; // Return the last reachable building index
                }
            }
        }
        // If we successfully loop through all buildings, we can reach the last one
        return heights.size() - 1;
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    
    // Test case 1
    vector<int> heights1 = {4, 2, 7, 6, 9, 14, 12};
    int bricks1 = 5, ladders1 = 1;
    cout << "Furthest Building: " << sol.furthestBuilding(heights1, bricks1, ladders1) << endl;
    
    // Test case 2
    vector<int> heights2 = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks2 = 10, ladders2 = 2;
    cout << "Furthest Building: " << sol.furthestBuilding(heights2, bricks2, ladders2) << endl;
    
    return 0;
}

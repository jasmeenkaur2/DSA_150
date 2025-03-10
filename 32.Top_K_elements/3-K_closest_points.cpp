#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-Heap: Store pairs (-distance, point index)
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto& point : points) {
            int x = point[0], y = point[1];
            int dist = x * x + y * y; // Squared distance

            maxHeap.push({dist, point}); // Insert into heap
            
            if (maxHeap.size() > k) {
                maxHeap.pop(); // Remove the farthest point
            }
        }

        // Collect the k closest points
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    vector<vector<int>> result = sol.kClosest(points, k);
    for (auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    return 0;
}

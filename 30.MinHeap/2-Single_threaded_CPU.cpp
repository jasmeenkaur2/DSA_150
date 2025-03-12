#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> result;

        // Step 1: Store tasks with original indices and sort by enqueueTime
        vector<vector<int>> sortedTasks;
        for (int i = 0; i < n; i++) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i}); // {enqueueTime, processingTime, index}
        }
        sort(sortedTasks.begin(), sortedTasks.end());

        // Step 2: Min-Heap to process tasks by {processingTime, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        long long currentTime = 0;
        int taskIndex = 0; // Index to iterate over sorted tasks

        while (taskIndex < n || !minHeap.empty()) {
            // Step 3: Push all available tasks into minHeap
            while (taskIndex < n && sortedTasks[taskIndex][0] <= currentTime) {
                minHeap.push({sortedTasks[taskIndex][1], sortedTasks[taskIndex][2]}); // {processingTime, index}
                taskIndex++;
            }

            // Step 4: If heap is empty, move time forward to next task's enqueueTime
            if (minHeap.empty()) {
                currentTime = sortedTasks[taskIndex][0];
                continue;
            }

            // Step 5: Process the shortest available task
            auto [processingTime, index] = minHeap.top();
            minHeap.pop();
            result.push_back(index);

            // Step 6: Update time after completing the task
            currentTime += processingTime;
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    
    vector<int> order = sol.getOrder(tasks);
    cout << "Order of task execution: ";
    for (int idx : order) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}

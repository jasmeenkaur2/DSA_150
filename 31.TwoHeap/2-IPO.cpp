#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> projects;
        int n = Profits.size();

        // Step 1: Store (capital, profit) pairs and sort by required capital
        for (int i = 0; i < n; i++) {
            projects.push_back({Capital[i], Profits[i]});
        }
        sort(projects.begin(), projects.end()); // Sort by capital needed (ascending)

        // Step 2: Max Heap to store affordable projects based on profit
        priority_queue<int> maxHeap;
        int i = 0;

        // Step 3: Pick up to k projects
        while (k--) {
            // Push all projects that can be started with current capital into maxHeap
            while (i < n && projects[i].first <= W) {
                maxHeap.push(projects[i].second);
                i++;
            }

            // If no project can be started, break
            if (maxHeap.empty()) break;

            // Step 4: Select the most profitable project
            W += maxHeap.top();
            maxHeap.pop();
        }

        return W; // Final maximized capital
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> Profits = {1, 2, 3};
    vector<int> Capital = {0, 1, 1};
    int k = 2, W = 0;

    int maxCapital = sol.findMaximizedCapital(k, W, Profits, Capital);
    cout << "Maximized Capital: " << maxCapital << endl;
    return 0;
}

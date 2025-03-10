#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // To store the frequency of each number
        for (int num : nums) {
            freq[num]++;  // Count frequency
        }

        // Min-Heap: stores (frequency, number)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Push elements into the heap
        for (auto& [num, count] : freq) {
            minHeap.push({count, num});  // Store frequency first for sorting
            if (minHeap.size() > k) {
                minHeap.pop();  // Remove the least frequent element
            }
        }

        // Extract top k elements
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    vector<int> result = sol.topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";  // Expected output: 1 2
    }
    return 0;
}

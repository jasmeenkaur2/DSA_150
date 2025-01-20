#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores indices of elements in the current window
        vector<int> result; // Stores the maximum of each sliding window

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of the current window
            // If the front of the deque is outside the window (i - k), remove it
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove indices of elements smaller than the current element nums[i]
            // As they cannot be the maximum in this or any future window
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back(); // Remove the smaller element at the back
            }

            // Add the current index to the deque
            dq.push_back(i);

            // If we have reached at least the first full window (i >= k - 1)
            // The maximum for the current window is at the front of the deque
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]); // Add the max to the result
            }
        }

        // Return the result containing the maximums for all sliding windows
        return result;
    }
};

int main()
{
 return 0;
}
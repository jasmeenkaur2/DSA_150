#include<iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct = nums[0]; // Initialize with the first element
        int currentMax = nums[0]; // Tracks the maximum product ending at the current position
        int currentMin = nums[0]; // Tracks the minimum product ending at the current position

        for (int i = 1; i < nums.size(); i++) {
            // If the current number is negative, swap currentMax and currentMin
            if (nums[i] < 0) {
                swap(currentMax, currentMin);
            }

            // Update currentMax and currentMin
            currentMax = max(nums[i], currentMax * nums[i]);
            currentMin = min(nums[i], currentMin * nums[i]);

            // Update the maximum product found so far
            maxproduct = max(maxproduct, currentMax);
        }

        return maxproduct;
    }
};

int main()
{
 return 0;
}
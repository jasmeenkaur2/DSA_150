#include<iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN; // Initialize maxsum to the smallest possible value
        int currentsum = 0;   // Initialize currentsum to 0
        
        for (int i = 0; i < nums.size(); i++) {
            currentsum += nums[i]; // Add the current element to currentsum
            
            // Update maxsum if currentsum is greater
            maxsum = max(currentsum, maxsum);
            
            // If currentsum becomes negative, reset it to 0
            if (currentsum < 0) {
                currentsum = 0;
            }
        }
        
        return maxsum; // Return the maximum sum of a subarray
    }
};

int main()
{
 return 0;
}
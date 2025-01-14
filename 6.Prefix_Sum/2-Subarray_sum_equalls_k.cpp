#include<iostream>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1; // Base case: there's one way to have a sum of 0
        
        for (int num : nums) {
            sum += num;
            // Check if there's a subarray ending at the current position that sums to k
            if (prefixSum.find(sum - k) != prefixSum.end()) {
                count += prefixSum[sum - k];
            }
            // Update the prefix sum frequency
            prefixSum[sum]++;
        }
        
        return count;
    }
};

int main()
{
 return 0;
}
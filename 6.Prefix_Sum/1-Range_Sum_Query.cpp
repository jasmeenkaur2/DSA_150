#include<iostream>
using namespace std;
class NumArray {
public:
    // A vector to store the prefix sums
    vector<int> prefix;

    // Constructor to initialize the prefix sum array
    NumArray(vector<int>& nums) {
        // Add the first element of nums to the prefix vector
        prefix.push_back(nums[0]);
        
        // Compute prefix sums for the rest of the elements
        for (int i = 1; i < nums.size(); i++) {
            // Each prefix[i] stores the sum of nums[0] to nums[i]
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
    }

    // Function to return the sum of elements between indices `left` and `right`
    int sumRange(int left, int right) {
        // If the range starts from index 0, the sum is just prefix[right]
        if (left == 0) {
            return prefix[right];
        } 
        // Otherwise, subtract prefix[left - 1] to exclude elements before `left`
        else {
            return prefix[right] - prefix[left - 1];
        }
    }
};

int main()
{
 return 0;
}
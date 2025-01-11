#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Sort the input array to group duplicates together
        sort(nums.begin(), nums.end());
        vector<int> once; // Vector to store the numbers that appear only once
        
        for (int i = 0; i < nums.size(); i++) {
            // If current element is equal to the next one, skip both
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++; // Move the index past the duplicate pair
            } else {
                // If the current element is not part of a pair, add it to the result
                once.push_back(nums[i]);
            }
        }

        return once; // Return the elements that appear only once
    }
};

int main()
{
 return 0;
}
#include<iostream>
#include<unordered_set>
using namespace std;

// this is the bruteforce approach using find function but with this approach time limit is exceeding.
int firstMissingPositive(std::vector<int>& nums) {
    int n = nums.size();

    // Iterate from 1 to n+1 using post-increment
    for (int i = 1; i <= n + 1; i++) {
        // Check if i is in the array
        if (std::find(nums.begin(), nums.end(), i) == nums.end()) {
            return i; // Return the first missing positive
        }
    }

    return 1; // This line is just for completeness, but won't be reached
}


//Using hashset 
// why set? - because set stores unique values in order.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    // Check each integer starting from 1
    for (int i = 1; i <= nums.size() + 1; i++) {
        // Return the first integer not found in set
        if (numSet.find(i) == numSet.end()) {
            return i;
        }
    }
    return 1; 
}
};

int main()
{
 return 0;
}
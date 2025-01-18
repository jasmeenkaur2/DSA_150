#include<iostream>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map; // To store cumulative sums and their first occurrences
        map[0] = -1; // Base case: sum = 0 before the array starts

        int maxLen = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Treat 0 as -1
            sum += (nums[i] == 0) ? -1 : 1;

            if (map.find(sum) != map.end()) {
                // Calculate the length of the subarray
                maxLen = max(maxLen, i - map[sum]);
            } else {
                // Store the first occurrence of this sum
                map[sum] = i;
            }
        }

        return maxLen;
    }
};
int main()
{
 return 0;
}
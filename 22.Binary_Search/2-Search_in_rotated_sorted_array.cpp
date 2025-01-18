#include<iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[start] <= nums[mid]) {
                // Check if the target lies in the left half
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1; // Search left half
                } else {
                    start = mid + 1; // Search right half
                }
            } 
            // Otherwise, the right half is sorted
            else {
                // Check if the target lies in the right half
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1; // Search right half
                } else {
                    end = mid - 1; // Search left half
                }
            }
        }

        return -1; // Target not found
    }
};

int main()
{
 return 0;
}
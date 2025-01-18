#include<iostream>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // Peak is in the left half or at mid
                end = mid;
            } else {
                // Peak is in the right half
                start = mid + 1;
            }
        }

        return start; // or end, as start == end
    }
};

int main()
{
 return 0;
}
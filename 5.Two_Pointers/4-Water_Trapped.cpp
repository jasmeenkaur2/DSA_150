#include<iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // If the height array is empty, no water can be trapped
        if (height.empty()) return 0;

        // Size of the height array
        int n = height.size();

        // Two pointers, starting from both ends of the array
        int left = 0, right = n - 1;

        // Variables to store the maximum heights seen so far from left and right
        int leftMax = 0, rightMax = 0;

        // Variable to store the total amount of water trapped
        int waterTrapped = 0;

        // Two-pointer traversal to calculate water trapped
        while (left < right) {
            // If the height at the left pointer is less than the height at the right pointer
            if (height[left] < height[right]) {
                // Check if the current height at 'left' is greater than or equal to 'leftMax'
                if (height[left] >= leftMax) {
                    // Update 'leftMax' as the current height
                    leftMax = height[left];
                } else {
                    // Add the trapped water at this index to 'waterTrapped'
                    waterTrapped += leftMax - height[left];
                }
                // Move the 'left' pointer to the right (post-increment)
                left++;
            } else {
                // If the height at the right pointer is less than or equal to the left pointer
                // Check if the current height at 'right' is greater than or equal to 'rightMax'
                if (height[right] >= rightMax) {
                    // Update 'rightMax' as the current height
                    rightMax = height[right];
                } else {
                    // Add the trapped water at this index to 'waterTrapped'
                    waterTrapped += rightMax - height[right];
                }
                // Move the 'right' pointer to the left (post-decrement)
                right--;
            }
        }

        // Return the total water trapped
        return waterTrapped;
    }
};

int main()
{
 return 0;
}
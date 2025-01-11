#include<iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // Calculate area using the shorter of the two heights and the width
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(area, max_area);

            // Move the pointer pointing to the shorter height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};

int main()
{
 return 0;
}
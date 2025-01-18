#include<iostream>
using namespace std;
class Solution {
public:
    // Function to calculate the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;  // Stack to store indices of the histogram bars
        int maxArea = 0;  // Variable to store the maximum area
        int n = heights.size();  // Number of bars in the histogram

        // Iterate through each bar in the histogram
        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current bar is shorter than the bar at the stack's top
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];  // Height of the bar to calculate the area
                st.pop();  // Remove the top element from the stack
                // Width of the rectangle:
                // If the stack is empty, the width extends from the beginning to the current index
                // Otherwise, the width is between the current index and the next index in the stack
                int width = st.empty() ? i : (i - st.top() - 1);
                // Update the maximum area
                maxArea = max(maxArea, height * width);
            }
            // Push the current bar's index onto the stack
            st.push(i);
        }

        // Handle remaining bars in the stack
        while (!st.empty()) {
            int height = heights[st.top()];  // Height of the bar
            st.pop();  // Remove the top element from the stack
            // Calculate the width as before
            int width = st.empty() ? n : (n - st.top() - 1);
            // Update the maximum area
            maxArea = max(maxArea, height * width);
        }

        return maxArea;  // Return the maximum area found
    }
};
int main()
{
 return 0;
}
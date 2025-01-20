#include<iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Perform binary search on the "flattened" matrix
        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Map mid to a (row, col) index in the 2D matrix
            int midValue = matrix[mid / n][mid % n];

            if (midValue == target) {
                return true;  // Found the target
            } else if (midValue < target) {
                low = mid + 1;  // Search in the right half
            } else {
                high = mid - 1;  // Search in the left half
            }
        }

        return false;  // Target not found
    }
};
int main()
{
 return 0;
}
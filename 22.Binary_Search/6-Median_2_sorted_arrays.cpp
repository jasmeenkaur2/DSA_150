#include <vector>
#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Ensure nums1 is the smaller array to minimize the number of elements in binary search
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2); // Swap arrays if nums1 is larger
    }

    int n = nums1.size();  // Length of the first array (smaller one)
    int m = nums2.size();  // Length of the second array
    int low = 0, high = n; // Binary search bounds for the smaller array

    while (low <= high) {
        // Calculate partition indices for nums1 and nums2
        int partition1 = (low + high) / 2;  // Partition index for nums1
        int partition2 = (n + m + 1) / 2 - partition1;  // Partition index for nums2

        // Get the maximum element on the left side of partition1 and partition2, and the minimum on the right
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1]; // Max on the left of nums1
        int minRight1 = (partition1 == n) ? INT_MAX : nums1[partition1];    // Min on the right of nums1

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1]; // Max on the left of nums2
        int minRight2 = (partition2 == m) ? INT_MAX : nums2[partition2];    // Min on the right of nums2

        // If we've found the correct partition
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // If the total length of the arrays is even, median is the average of the two middle elements
            if ((n + m) % 2 == 0) {
                // Average of the maximum of the left part and the minimum of the right part
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                // If the total length is odd, the median is the maximum of the left parts
                return max(maxLeft1, maxLeft2);
            }
        } 
        // If maxLeft1 is greater than minRight2, move the partition1 left (reduce the number of elements in the left part)
        else if (maxLeft1 > minRight2) {
            high = partition1 - 1;  // Adjust the search range for partition1
        } 
        // If maxLeft2 is greater than minRight1, move the partition1 right (increase the number of elements in the left part)
        else {
            low = partition1 + 1;  // Adjust the search range for partition1
        }
    }

    // If we reach here, it means the input arrays are not sorted correctly, though this should not happen with valid inputs
    throw invalid_argument("Input arrays are not sorted.");
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    cout << "Median: " << findMedianSortedArrays(nums1_2, nums2_2) << endl;

    return 0;
}

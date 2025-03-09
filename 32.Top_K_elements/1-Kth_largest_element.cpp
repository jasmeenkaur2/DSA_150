#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap to track k largest elements
    int k; // The k-th largest position

public:
    // Constructor: Initialize the KthLargest object with k and nums
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num); // Insert elements using add() to maintain heap property
        }
    }

    // Function to add a new value and return the k-th largest element
    int add(int val) {
        minHeap.push(val); // Insert the new value
        if (minHeap.size() > k) { 
            minHeap.pop(); // Remove the smallest element to maintain k elements
        }
        return minHeap.top(); // The top is the k-th largest element
    }
};

// Driver Code
int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums); // k = 3, stream = {4,5,8,2}

    cout << kthLargest.add(3) << endl;  // Output: 4
    cout << kthLargest.add(5) << endl;  // Output: 5
    cout << kthLargest.add(10) << endl; // Output: 5
    cout << kthLargest.add(9) << endl;  // Output: 8
    cout << kthLargest.add(4) << endl;  // Output: 8

    return 0;
}

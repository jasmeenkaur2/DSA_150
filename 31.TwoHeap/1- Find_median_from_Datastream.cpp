#include <iostream>
#include <queue>
using namespace std;

// Class to maintain the median of a stream of numbers
class MedianFinder {
private:
    priority_queue<int> low; // Max Heap (stores smaller half)
    priority_queue<int, vector<int>, greater<int>> high; // Min Heap (stores larger half)

public:
    /** Initialize the data structure */
    MedianFinder() {}

    /** Adds a number into the data structure */
    void addNum(int num) {
        // Step 1: Insert into max heap first
        low.push(num);

        // Step 2: Balance by moving the max element of `low` to `high`
        high.push(low.top());
        low.pop();

        // Step 3: Ensure `low` has equal or one more element than `high`
        if (low.size() < high.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    /** Returns the median of all elements */
    double findMedian() {
        if (low.size() > high.size()) {
            return low.top(); // Odd case: max heap top is median
        }
        return (low.top() + high.top()) / 2.0; // Even case: average of two tops
    }
};

// Driver function to test the MedianFinder class
int main() {
    MedianFinder medianFinder;
    
    // Test Case
    int numbers[] = {5, 15, 1, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < n; i++) {
        medianFinder.addNum(numbers[i]);
        cout << "Inserted: " << numbers[i] << ", Median: " << medianFinder.findMedian() << endl;
    }

    return 0;
}

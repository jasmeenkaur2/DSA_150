#include <iostream>
#include <vector>
#include <algorithm> // For max_element function
using namespace std;

class Solution {
public:
    // Function to check if Koko can eat all bananas in h hours at speed k
    bool canEat(vector<int>& piles, int h, int k) {
        int hours = 0;

        // Calculate total hours required to eat all piles at speed k
        for (int pile : piles) {
            // Using integer math to calculate ceil(pile / k)
            hours += (pile + k - 1) / k; // Trick to simulate ceiling without floating-point math
            if (hours > h) {
                // Early exit if the hours exceed h, no need to check further
                return false;
            }
        }

        // Return true if Koko can finish in h hours or less
        return hours <= h;
    }

    // Function to find the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary search for the minimum speed k
        int left = 1; // The smallest possible speed is 1
        int right = *max_element(piles.begin(), piles.end()); // Maximum pile size
        int result = right; // Initialize result with the largest possible speed

        while (left <= right) {
            int mid = left + (right - left) / 2; // Middle speed (candidate speed)

            // If Koko can finish eating at speed mid in h hours
            if (canEat(piles, h, mid)) {
                result = mid; // Update the result to mid (valid speed)
                right = mid - 1; // Try a smaller speed
            } else {
                left = mid + 1; // If it's not valid, try a larger speed
            }
        }
        
        // Return the smallest valid speed
        return result;
    }
};

int main() {
    // Example usage
    vector<int> piles = {3, 6, 7, 11}; // Bananas in each pile
    int h = 8; // Hours to finish all bananas
    
    // Create an instance of Solution class and call minEatingSpeed
    Solution sol;
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles, h) << endl;

    return 0;
}

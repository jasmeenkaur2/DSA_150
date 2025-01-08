#include<iostream>
using namespace std;

class Solution{
 public:

 //Brute Force Approach

 class solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int count = 0;
            // Count occurrences of nums[i]
            for (int j = 0; j < n; ++j) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }
            // If count is more than n/2, we've found our majority element
            if (count > n / 2) {
                return nums[i];
            }
        }
        return -1; // Majority element must exist, this is a safeguard
    }
};

/*Time and Space Complexity

Time Complexity: O(n^2), where n is the number of elements in the array.
Space Complexity: O(1), no extra space used.

******************************************************************************/

//Sorting - As we know majorit element have occurences more than n/2 so sort the list and return the middle element.


int MajorityElement(vector <int> & nums){
    sort(nums.begin(),nums.end());

    return nums[nums.size()/2];
}

/*Time and Space Complexity

Time Complexity: O(n log n), due to the sorting operation.
Space Complexity: O(1), if we disregard the space used by the internal sorting algorithm.*/

//Using Unordered Map

class solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> countmap;

        for(int num:nums){
            countmap[num]++;
            
        if(countmap[num]>n/2)
            return num;
        }

        return -1;
    }
};

/*Time and Space Complexity

Time Complexity: O(n), where n is the number of elements in the array.
Space Complexity: O(n), for storing frequencies in the hash map.*/

};
int main()
{
 return 0;
}
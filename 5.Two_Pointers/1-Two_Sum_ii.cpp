#include<iostream>
using namespace std;

//Brute Force Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i = 0; i<n;i++){
            for(int j = i+1;j<n;j++){
                if(numbers[i]+numbers[j]== target){
                    return {i+1,j+1};
                }
            }
        }
        return {};
    }
};

//Two pointer approach

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1; // Initialize pointers at the start and end of the array

        // Loop until the pointers meet
        while (left < right) {
            int sum = numbers[left] + numbers[right]; // Calculate the sum of the current two numbers

            if (sum == target) {
                // If the sum matches the target, return the 1-based indices
                return {left + 1, right + 1};
            } else if (sum < target) {
                // If the sum is less than the target, move the left pointer to the right
                left++;
            } else {
                // If the sum is greater than the target, move the right pointer to the left
                right--;
            }
        }

        return {}; // Return an empty vector if no solution is found
    }
};

int main()
{
 return 0;
}
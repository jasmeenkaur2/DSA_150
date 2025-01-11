#include<iostream>
#include<set>
using namespace std;

//Brute force approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> result; // Use set to avoid duplicate triplets
        
        // Iterate over each triplet
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end()); // Sort to avoid duplicates
                        result.insert(triplet);
                    }
                }
            }
        }
        
        return vector<vector<int>>(result.begin(), result.end());
    }
};

//Two pointer Approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the vector to facilitate the two-pointer approach
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate elements
            
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum < 0) {
                    left++; // Move the left pointer to increase the sum
                } else if (sum > 0) {
                    right--; // Move the right pointer to decrease the sum
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // Avoid duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Avoid duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        
        return result;
    }
};
int main()
{
 return 0;
}
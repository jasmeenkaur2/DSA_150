#include<iostream>
using namespace std;


//Brute Force approach time limit exceeding in some test cases
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i<n; i++){
            for(int j = i+1;j<n;j++){
                if(nums[i]==nums[j] && abs(i-j)<=k){
                    return true;
                }
            }
        }
        return false;
    }
};

//Using Hash Table
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            // Check if nums[i] exists in the map and if the difference is within k
            if (m.find(nums[i]) != m.end() && abs(m[nums[i]] - i) <= k) {
                return true;
            }
            // Update the latest index of nums[i]
            m[nums[i]] = i;
        }
        return false;
    }
};
int main()
{
 return 0;
}
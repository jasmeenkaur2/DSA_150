#include<iostream>
using namespace std;

class Solution{

    public:

    void move_zeroes(vector<int>& nums){

        int j = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]!= 0){
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }
};

//Complexity Analysis:

/*Time Complexity: O(n), where n is the number of elements in the array. Each element is visited exactly once.
Space Complexity: O(1), as we perform the entire operation in-place with constant extra space.
int main()*/


int main()
{
 return 0;
}
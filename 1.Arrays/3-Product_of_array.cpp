#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>l_product(n),r_product(n),final_product(n);
        
//left array product
        l_product[0]=1;
        for(int i = 1; i<n;i++){
            l_product[i] = l_product[i-1]*nums[i-1];
        }
//right array product
        r_product[n-1]=1;
        for(int i = n-2;i>=0;i--){
            r_product[i] = r_product[i+1]*nums[i+1];
        }

//product of left and right array
        for(int i=0;i<n;i++){
            final_product[i]=l_product[i]*r_product[i];

        }

        return final_product;
    }
};
int main()
{
 return 0;
}
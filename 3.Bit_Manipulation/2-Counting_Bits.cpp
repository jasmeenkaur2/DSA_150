#include<iostream>
using namespace std;
class Solution {
public:
    // Function to count the number of 1s in binary representation for numbers from 0 to num
    std::vector<int> countBits(int num) {
        std::vector<int> result(num + 1, 0); // Initialize the result vector with size num + 1
        for (int i = 0; i <= num; ++i) {
            int count = 0;
            int n = i;
            while (n) {
                count += n & 1; // Add 1 if the least significant bit is 1
                n >>= 1;        // Shift the number to the right by 1 bit
            }
            result[i] = count; // Store the count of 1s for the number i
        }
        return result;
    }
};

int main()
{
 return 0;
}
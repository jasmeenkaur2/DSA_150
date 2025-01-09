#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            // Add to profit if today's price is higher than yesterday's
            if (prices[i] > prices[i - 1]) {
                maxProfit += (prices[i] - prices[i - 1]);
            }
        }
        return maxProfit;
    }
};
int main()
{
 return 0;
}


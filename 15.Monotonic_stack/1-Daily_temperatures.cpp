#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> days(n, 0); // Initialize result array with 0
        stack<int> st; // Monotonic decreasing stack (stores indices)

        for (int i = 0; i < n; i++) {
            // Process stack while current temperature is higher
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                days[index] = i - index; // Calculate number of days
            }
            st.push(i); // Push current index onto the stack
        }

        return days;
    }
};

int main()
{
 return 0;
}
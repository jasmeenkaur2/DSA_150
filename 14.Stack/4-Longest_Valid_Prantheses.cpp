#include<iostream>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxlength = 0;
        st.push(-1); // Marker for the start of a valid substring

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push the index of '('
            } else {
                st.pop(); // Pop the stack for ')'
                if (st.empty()) {
                    st.push(i); // Push current index as a new marker
                } else {
                    maxlength = max(maxlength, i - st.top());
                }
            }
        }

        return maxlength;
    }
};

int main()
{
 return 0;
}
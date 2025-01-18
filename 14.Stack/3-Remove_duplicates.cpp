#include<iostream>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0); // Frequency array for characters
        vector<bool> visited(26, false); // Visited array to track stack inclusion
        stack<char> st; // Monotonic stack to maintain lexicographical order

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Iterate through the string
        for (char c : s) {
            freq[c - 'a']--; // Decrease frequency of current character

            // Skip if the character is already in the stack
            if (visited[c - 'a']) continue;

            // Remove characters from the stack if:
            // - They are greater than the current character (to maintain lexicographical order)
            // - They appear later in the string (freq[st.top() - 'a'] > 0)
            while (!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            // Add the current character to the stack
            st.push(c);
            visited[c - 'a'] = true;
        }

        // Build the result string
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Reverse the result as the stack produces it in reverse order
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
 return 0;
}
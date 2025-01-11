#include<iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {

        string str = ""; // Temporary variable to hold each word
        stack<string> sk; // Stack to store words in reverse order
        string ans = ""; // Final result string

        // Loop through each character of the string `s`
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') { // Check if the character is a space
                if (str != "") { // If the current word is not empty
                    sk.push(str); // Push the word onto the stack
                    str = ""; // Reset `str` for the next word
                }
            } else {
                str = str + s[i]; // Append the character to the current word
            }
        }

        // After the loop, check if there's a leftover word in `str`
        if (!str.empty()) {
            sk.push(str); // Push the last word onto the stack
        }

        // Pop words from the stack and build the reversed string
        while (!sk.empty()) {
            if (sk.size() == 1) { // If it's the last word in the stack
                ans = ans + sk.top(); // Append the word without a trailing space
            } else {
                ans = ans + sk.top() + " "; // Append the word followed by a space
            }
            sk.pop(); // Remove the top word from the stack
        }

        return ans; // Return the final reversed string
    }
};

int main()
{
 return 0;
}
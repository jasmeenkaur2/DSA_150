#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> v; // Stack to store opening brackets

        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '[' || c == '{') {
                v.push(c);
            } 
            // Check closing brackets
            else {
                // If stack is empty or doesn't match, return false
                if (v.empty() || 
                    (c == ')' && v.top() != '(') ||
                    (c == ']' && v.top() != '[') ||
                    (c == '}' && v.top() != '{')) {
                    return false;
                }
                v.pop(); // Pop matching opening bracket
            }
        }

        // Return true if stack is empty (all brackets matched)
        return v.empty();
    }
};

// Driver code
int main() {
    Solution solution;
    string s;

    // Input the string
    cout << "Enter a string of parentheses: ";
    cin >> s;

    // Check if the string is valid
    if (solution.isValid(s)) {
        cout << "The string is valid!" << endl;
    } else {
        cout << "The string is not valid!" << endl;
    }

    return 0;
}

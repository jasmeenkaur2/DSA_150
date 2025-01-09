#include<iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        
        // Traverse both strings
        while (i < n && j < m) {
            // If characters match, move to the next character in s
            if (s[i] == t[j])
                i++;
            // Move to the next character in t
            j++;
        }
        
        // If all characters of s are found in t in order, return true
        return i == n; //basically here we are comparing in numbers if size of s and occurences of s in t are same using i as count.
    }
};
int main()
{
 return 0;
}
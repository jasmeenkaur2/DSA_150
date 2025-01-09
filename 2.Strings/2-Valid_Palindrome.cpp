#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1; // Initialize two pointers: one starting at the beginning and the other at the end of the string.
        
        while(left < right) { // Loop until the two pointers meet or cross each other.
            
            // Move the left pointer to the next alphanumeric character.
            // Skip any characters that are not letters or digits.
            while (left < right && !isalnum(s[left])) {
                left++; // Increment the left pointer to examine the next character.
            }
            
            // Move the right pointer to the previous alphanumeric character.
            // Skip any characters that are not letters or digits.
            while (right > left && !isalnum(s[right])) {
                right--; // Decrement the right pointer to examine the previous character.
            }
            
            // Compare the characters at the left and right pointers (ignoring case).
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // If the characters do not match, it's not a palindrome.
            }
            
            // Move both pointers inward to continue comparing the next set of characters.
            left++;
            right--;
        }
        
        return true; // If all comparisons succeed, the string is a palindrome.
    }
};

int main()
{
 return 0;
}
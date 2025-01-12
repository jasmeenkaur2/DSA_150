#include<iostream>
using namespace std;

class Solution {
public:
    // Function to group anagrams from a list of strings
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store groups of anagrams
        // Key: Sorted version of a string
        // Value: List of strings that are anagrams of the key
        unordered_map<string, vector<string>> groups;

        // Iterate over each string in the input list
        for (auto str : strs) {
            string sorted_str = str;               // Copy the original string
            sort(sorted_str.begin(), sorted_str.end()); // Sort the characters in the string
            groups[sorted_str].push_back(str);     // Group the original string under the sorted key
        }

        // Prepare the result vector to store grouped anagrams
        vector<vector<string>> result;

        // Add each group of anagrams from the map to the result
        for (auto group : groups) {
            result.push_back(group.second); // `group.second` contains all anagrams for the key
        }

        return result; // Return the 2D vector containing grouped anagrams
    }
};

int main()
{
 return 0;
}
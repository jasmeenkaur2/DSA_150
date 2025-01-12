#include<iostream>
using namespace std;
class Solution {
public:
    // Function to check if two strings are isomorphic
    bool isIsomorphic(string s, string t) {

        // If the strings have different lengths, they cannot be isomorphic
        if (s.length() != t.length())
            return false;

        // Maps to store the character mappings between the two strings
        unordered_map<char, char> mapST; // Maps characters from `s` to `t`
        unordered_map<char, char> mapTS; // Maps characters from `t` to `s`

        // Loop through all characters in both strings
        for (int i = 0; i < s.length(); i++) {
            char ST = s[i]; // Current character in string `s`
            char TS = t[i]; // Current character in string `t`

            // Check for inconsistencies in the mappings:
            // - If `ST` is mapped to a different character than `TS` in `mapST`
            // - OR if `TS` is mapped to a different character than `ST` in `mapTS`
            if ((mapST.count(ST) && mapST[ST] != TS) ||
                (mapTS.count(TS) && mapTS[TS] != ST)) {
                return false; // Mappings are inconsistent; strings are not isomorphic
            }

            // Add the new mappings (or confirm existing mappings)
            mapST[ST] = TS; // Map `ST` to `TS` in `mapST`
            mapTS[TS] = ST; // Map `TS` to `ST` in `mapTS`
        }

        // If the loop completes without conflicts, the strings are isomorphic
        return true;
    }
};

int main()
{
 return 0;
}
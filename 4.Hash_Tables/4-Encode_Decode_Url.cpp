#include<iostream>
using namespace std;

class Solution {
    // Maps to store the relationship between long URLs and short URLs
    unordered_map<string, string> longtoshort; // Maps long URLs to their corresponding tiny URLs
    unordered_map<string, string> shorttolong; // Maps tiny URLs back to their original long URLs
    int id = 1; // A counter to generate unique IDs for tiny URLs

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // Check if the long URL is already encoded
        if (longtoshort.find(longUrl) != longtoshort.end()) {
            // If found, return the already generated tiny URL
            return longtoshort[longUrl];
        }

        // Generate a new unique tiny URL
        string tinyurl = "http://tinyurl.com/" + to_string(id);
        id++; // Increment the counter for the next unique tiny URL

        // Store the mappings for both directions
        longtoshort[longUrl] = tinyurl; // Map the long URL to the tiny URL
        shorttolong[tinyurl] = longUrl; // Map the tiny URL back to the long URL

        return tinyurl; // Return the newly generated tiny URL
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // Check if the tiny URL exists in the mapping
        if (shorttolong.find(shortUrl) != shorttolong.end()) {
            // If found, return the corresponding long URL
            return shorttolong[shortUrl];
        }

        // If the tiny URL does not exist, return an empty string
        return "";
    }
};

int main()
{
 return 0;
}
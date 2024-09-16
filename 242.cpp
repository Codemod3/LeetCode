#include <iostream>
#include <string>
#include <algorithm> // For std::sort
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size())
        return false;

        unordered_map<int,int> map;
        for(int i =0;i<s.size();i++)
        {
            map[s[i]]++;

        }
        for(int i =0;i<t.size();i++)
        {
            if(map.find(t[i]) == map.end() || map[t[i]] == 0)
            return false;
            map[t[i]]--;
            
        }
        return true;
        
    }
};

// Helper function to test the isAnagram function
void testAnagram(const string& s, const string& t, bool expected) {
    Solution solution;
    bool result = solution.isAnagram(s, t);
    cout << "s: " << s << "\nt: " << t << "\nExpected: " << (expected ? "true" : "false") << "\nResult: " << (result ? "true" : "false") << endl;
}

int main() {
    // Test cases
    testAnagram("anagram", "nagaram", true);
    testAnagram("rat", "car", false);
    testAnagram("listen", "silent", true);
    testAnagram("hello", "world", false);

    return 0;
}


/*242. Valid Anagram
Solved
Easy
Topics
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false*/
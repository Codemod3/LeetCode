#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> dup;

        for (int i = s.size() - 1; i >= 0; i--) {
            dup.push_back(s[i]);
        }
        for (int i = 0; i < s.size(); i++) {
            s[i] = dup[i];
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of characters in the string: ";
    cin >> n;

    vector<char> s(n);
    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    Solution solution;
    solution.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}


/*344. Reverse String
Solved
Easy
Topics
Companies
Hint
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]*/
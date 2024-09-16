#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> k;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                k.push(s[i]);
            } else {
                if (k.empty())
                    return false;
                if (k.top() == '(' && s[i] == ')')
                    k.pop();
                else if (k.top() == '[' && s[i] == ']')
                    k.pop();
                else if (k.top() == '{' && s[i] == '}')
                    k.pop();
                else
                    return false;
            }
            i++;
        }
        return k.empty();
    }
};

int main() {
    string s;
    
    // Input the string of parentheses
    cout << "Enter a string of parentheses: ";
    cin >> s;
    
    Solution solution;
    bool result = solution.isValid(s);
    
    // Output the result
    if (result) {
        cout << "The string of parentheses is valid." << endl;
    } else {
        cout << "The string of parentheses is not valid." << endl;
    }

    return 0;
}
/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 */
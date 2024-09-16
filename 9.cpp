#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long dup = x;
        long rev = 0;
        while (dup != 0) {
            int k = dup % 10;
            rev = rev * 10 + k;
            dup /= 10;
        }
        return rev == x;
    }
};

int main() {
    int x;
    
    // Input the integer
    cout << "Enter an integer: ";
    cin >> x;
    
    Solution solution;
    bool result = solution.isPalindrome(x);
    
    // Output the result
    if (result) {
        cout << x << " is a palindrome." << endl;
    } else {
        cout << x << " is not a palindrome." << endl;
    }

    return 0;
}

/*
Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
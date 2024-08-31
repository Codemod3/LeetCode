#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'M') {
                sum = sum + 1000;
            } else if (s[i] == 'D') {
                if (i + 1 < n && s[i + 1] == 'M') {
                    i++;
                    sum = sum + 500;
                } else {
                    sum = sum + 500;
                }
            } else if (s[i] == 'C') {
                if (i + 1 < n && s[i + 1] == 'D') {
                    i++;
                    sum = sum + 400;
                } else if (i + 1 < n && s[i + 1] == 'M') {
                    i++;
                    sum = sum + 900;
                } else {
                    sum = sum + 100;
                }
            } else if (s[i] == 'L') {
                if (i + 1 < n && s[i + 1] == 'C') {
                    i++;
                    sum = sum + 50;
                } else if (i + 1 < n && s[i + 1] == 'D') {
                    i++;
                    sum = sum + 450;
                } else if (i + 1 < n && s[i + 1] == 'M') {
                    i++;
                    sum = sum + 950;
                } else {
                    sum = sum + 50;
                }
            } else if (s[i] == 'X') {
                if (i + 1 < n && s[i + 1] == 'L') {
                    i++;
                    sum = sum + 40;
                } else if (i + 1 < n && s[i + 1] == 'C') {
                    i++;
                    sum = sum + 90;
                } else if (i + 1 < n && s[i + 1] == 'D') {
                    i++;
                    sum = sum + 490;
                } else if (i + 1 < n && s[i + 1] == 'M') {
                    i++;
                    sum = sum + 990;
                } else {
                    sum = sum + 10;
                }
            } else if (s[i] == 'V') {
                if (i + 1 < n && s[i + 1] == 'X') {
                    i++;
                    sum = sum + 5;
                } else if (i + 1 < n && s[i + 1] == 'L') {
                    i++;
                    sum = sum + 45;
                } else if (i + 1 < n && s[i + 1] == 'C') {
                    i++;
                    sum = sum + 95;
                } else if (i + 1 < n && s[i + 1] == 'D') {
                    i++;
                    sum = sum + 495;
                } else if (i + 1 < n && s[i + 1] == 'M') {
                    i++;
                    sum = sum + 995;
                } else {
                    sum = sum + 5;
                }
            } else if (s[i] == 'I') {
                if (i + 1 < n && s[i + 1] == 'V') {
                    i++;
                    sum = sum + 4;
                } else if (i + 1 < n && s[i + 1] == 'X') {
                    i++;
                    sum = sum + 9;
                } else if (i + 1 < n && s[i + 1] == 'L') {
                    i++;
                    sum = sum + 49;
                } else if (i + 1 < n && s[i + 1] == 'C') {
                    i++;
                    sum = sum + 99;
                } else if (i + 1 < n && s[i + 1] == 'D') {
                    i++;
                    sum = sum + 499;
                } else if (i + 1 < n && s[i + 1] == 'M') {
                    i++;
                    sum = sum + 999;
                } else {
                    sum = sum + 1;
                }
            }
        }
        return sum;
    }
};

int main() {
    string s;
    
    // Input the Roman numeral
    cout << "Enter a Roman numeral: ";
    cin >> s;
    
    Solution solution;
    int result = solution.romanToInt(s);
    
    // Output the result
    cout << "The integer value of the Roman numeral " << s << " is: " << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;

        for(int i = 0; i<nums.size();i++) {
            map[nums[i]]++;
            if(map[nums[i]]>1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Sample Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Test Case 1: ";
    cout << (solution.containsDuplicate(nums1) ? "True" : "False") << endl;
    // Expected Output: False

    // Sample Test Case 2
    vector<int> nums2 = {1, 2, 3, 4, 5, 2};
    cout << "Test Case 2: ";
    cout << (solution.containsDuplicate(nums2) ? "True" : "False") << endl;
    // Expected Output: True

    return 0;
}

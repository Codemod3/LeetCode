#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(const vector<int>& nums) const {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }

        // Verify that the candidate is indeed the majority element
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        if (count > nums.size() / 2) {
            return candidate;
        }

        // No majority element found
        return 0;
    }
};

// Helper function to test the majorityElement function
void testMajorityElement(const vector<int>& nums, int expected) {
    Solution solution;
    int result = solution.majorityElement(nums);
    cout << "Array: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]\nExpected: " << expected << "\nResult: " << result << endl;
}

int main() {
    // Test cases
    testMajorityElement({3, 2, 3}, 3);
    testMajorityElement({2, 2, 1, 1, 1, 2, 2}, 2);
    testMajorityElement({1, 1, 1, 2, 2, 2, 2}, 2);
    testMajorityElement({1, 2, 3, 4, 5}, 0); // No majority element

    return 0;
}

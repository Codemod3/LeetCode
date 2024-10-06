#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target) const {
        int f = 0;
        int mid;
        int l = nums.size() - 1;
        while (f <= l) {
            mid = (f + l) / 2;
            if (target > nums[mid]) {
                f = mid + 1;
            } else if (target < nums[mid]) {
                l = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

// Helper function to test the search function
void testSearch(const vector<int>& nums, int target, int expected) {
    Solution solution;
    int result = solution.search(nums, target);
    cout << "Array: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]\nTarget: " << target << "\nExpected: " << expected << "\nResult: " << result << endl;
}

int main() {
    // Test cases
    testSearch({-1, 0, 3, 5, 9, 12}, 9, 4);
    testSearch({-1, 0, 3, 5, 9, 12}, 2, -1);
    testSearch({1, 2, 3, 4, 5, 6, 7, 8, 9}, 5, 4);
    testSearch({1, 3, 5, 7, 9}, 1, 0);
    testSearch({1, 3, 5, 7, 9}, 9, 4);

    return 0;
}

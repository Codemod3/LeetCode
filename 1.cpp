#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> val;
        val.push_back(0);
        val.push_back(1);
        int sum = nums[0] + nums[1];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    val[0] = i; val[1] = j;
                    return val;
                }
                if (nums[i] + nums[j] > sum && nums[i] + nums[j] <= target) {
                    val[0] = i;
                    val[1] = j;
                }
            }
        }
        return val;
    }
};

int main() {
    int n, target;
    
    // Input the number of elements
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    
    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Input the target value
    cout << "Enter the target value: ";
    cin >> target;
    
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    
    // Output the result
    cout << "Indices of the two numbers that add up to the target are: ";
    cout << result[0] << " and " << result[1] << endl;

    return 0;
}

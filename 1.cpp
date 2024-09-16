#include <iostream>
#include <vector>

using namespace std;

#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        unordered_map<int, int> num_map;

        for(int i =0; i< nums.size(); i++){
            int complement = target - nums[i];

            if(num_map.find(complement) != num_map.end()){
                 return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    
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

/*Title: Two Sum

Problem Statement: Given an array of integers nums and an integer target, return the indices of the two numbers that add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice.

Explanation:

The function twoSum iterates through all pairs of indices in the nums array to check if their sum equals the target.
It keeps track of the indices of the pair that adds up to the target and returns them.
If no such pair is found, it returns the initial indices [0, 1] which may not be the correct result.
Sample Input:

mathematica

Enter the number of elements in the array: 4
Enter the elements of the array: 2 7 11 15
Enter the target value: 9
Sample Output:

sql

Indices of the two numbers that add up to the target are: 0 and 1 */

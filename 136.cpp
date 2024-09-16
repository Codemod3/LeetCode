#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i += 2) {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }

        // If no single number was found in the loop, return the last element
        return nums.back();
    }
};


/*
136. Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 */
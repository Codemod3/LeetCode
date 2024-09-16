#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // Handle empty input
        
        int j = 0;  // Index for the last unique element
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                j++;  // Move to the next position for a unique element
                nums[j] = nums[i];  // Update the element
            }
        }
        
        // Return the length of the unique elements array
        return j + 1;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& nums, int length) {
    for (int i = 0; i < length; ++i) {
        cout << nums[i];
        if (i < length - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    // Test case
    vector<int> nums = {1, 1, 2, 3, 3, 4, 5, 5, 6};
    
    Solution solution;
    int newLength = solution.removeDuplicates(nums);
    
    cout << "Array after removing duplicates: ";
    printVector(nums, newLength);

    return 0;
}

/*
26. Remove Duplicates from Sorted Array

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 */
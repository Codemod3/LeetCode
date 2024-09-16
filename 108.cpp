#include <iostream>
#include <vector>
using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sort(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sort(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        if (start > end)
            return nullptr;

        TreeNode* b = new TreeNode(nums[mid]);
        b->left = sort(nums, start, mid - 1);
        b->right = sort(nums, mid + 1, end);
        return b;
    }
};

// Helper function to print the tree in-order (for testing)
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main() {
    int n;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the sorted elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);

    cout << "In-order traversal of the constructed BST: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

/*

108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.*/
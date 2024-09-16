#include <iostream>
#include <vector>     // Include vector
#include <algorithm>  // For std::max

using namespace std;

// Definition for a binary tree node.
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }
};

// Helper function to create a binary tree from a vector
TreeNode* createTree(const vector<int>& values, int index) {
    if (index >= values.size() || values[index] == -1) // Use -1 to represent null nodes
        return nullptr;
    
    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}

// Helper function to test the maxDepth function
void testMaxDepth(const vector<int>& values, int expected) {
    TreeNode* root = createTree(values, 0);
    Solution solution;
    int result = solution.maxDepth(root);
    cout << "Expected: " << expected << ", Result: " << result << endl;

    // Clean up memory (note: proper tree deletion should be done, simplified here)
    delete root;
}

int main() {
    // Test cases
    testMaxDepth({3, 9, 20, -1, -1, 15, 7}, 3); // Example tree: [3,9,20,null,null,15,7]
    testMaxDepth({1, -1, 2}, 2);               // Example tree: [1,null,2]
    testMaxDepth({}, 0);                       // Empty tree
    testMaxDepth({0}, 1);                      // Single node tree

    return 0;
}


/*


104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 */
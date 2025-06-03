/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start

#ifndef TREENODE_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* tree = HalfArrayToBST(nums, 0, nums.size() - 1);
        return tree;
    }

    TreeNode* HalfArrayToBST(vector<int>& nums, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = HalfArrayToBST(nums, left, mid - 1);
        node->right = HalfArrayToBST(nums, mid + 1, right);
        return node;
    }
};
// @lc code=end


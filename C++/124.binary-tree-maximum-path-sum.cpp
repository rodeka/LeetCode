/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        max_sum = root->val;
        findSum(root);
        return max_sum;
    }

    int max_sum;

    int findSum(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }

        int left_side  = max(0, findSum(node->left));
        int right_side = max(0, findSum(node->right));

        int new_path = node->val + left_side + right_side;
        max_sum = max(max_sum, new_path);

        return node->val + max(left_side, right_side);
    }
};
// @lc code=end


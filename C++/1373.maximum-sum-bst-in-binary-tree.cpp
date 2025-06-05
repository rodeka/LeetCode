/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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
    int maxSumBST(TreeNode* root) {
        max_sum = 0;
        validMaxSumBST(root);
        return max_sum;
    }

    int max_sum;

    struct Info
    {
        bool isBST;
        int min_val;
        int max_val;
        int sum;
    };

    Info validMaxSumBST(TreeNode* node) {
        if(node == nullptr) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        Info left_side = validMaxSumBST(node->left);
        Info right_side = validMaxSumBST(node->right);

        if(left_side.isBST && right_side.isBST && node->val > left_side.max_val && node->val < right_side.min_val) {
            Info curr;
            curr.isBST = true;
            curr.sum = node->val + left_side.sum + right_side.sum;
            curr.min_val = node->left ? left_side.min_val : node->val;
            curr.max_val = node->right ? right_side.max_val : node->val;

            max_sum = max(max_sum, curr.sum);
            return curr;
        }
        return {false, INT_MIN, INT_MAX, 0};
    }
};
// @lc code=end


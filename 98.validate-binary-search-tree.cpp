/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        return isValidBSTrec(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }

    bool isValidBSTrec(TreeNode* node, long long min_val, long long max_val) {
        if((long long)node->val >= max_val || (long long)node->val <= min_val)
            return false;
        if(node->left)
            if(!isValidBSTrec(node->left, min_val, (long long)node->val))
                return false;
        if(node->right)
            if(!isValidBSTrec(node->right, (long long)node->val, max_val))
                return false;
        return true;
    }
};
// @lc code=end


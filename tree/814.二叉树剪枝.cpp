/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode* pruneTree(TreeNode* root)
    {
        if (post_order_recur(root) == 0)
        {
            return nullptr;
        }
        else
        {
            return root;
        }
    }

private:
    int post_order_recur(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int left_val = post_order_recur(node->left);
        if (left_val == 0)
        {
            node->left = nullptr;
        }
        int right_val = post_order_recur(node->right);
        if (right_val == 0)
        {
            node->right = nullptr;
        }

        return left_val + right_val + node->val;
    }
};
// @lc code=end

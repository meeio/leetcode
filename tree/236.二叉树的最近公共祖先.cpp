/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef TreeNode;

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        travel(root, p, q);
        return ans_;
    }

private:
    TreeNode* ans_;

    bool travel(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return false;
        }

        bool is_in_left = travel(root->left, p, q);
        bool is_in_right = travel(root->right, p, q);

        if (is_in_left && is_in_right)
        {
            ans_ = root;
            return true;
        }
        else if ( is_in_left ^ is_in_right)
        {
            if (root->val == p->val || root->val == q->val)
            {
                ans_ = root;
            }
            return true;
        }
        else
        {
            return root->val == p->val || root->val == q->val;
        }

    }
};
// @lc code=end

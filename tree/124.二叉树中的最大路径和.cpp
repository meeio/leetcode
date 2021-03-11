/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

#include<bits/stdc++.h>
#include<algorithm>

class Solution
{
public:
    int ans = INT_MIN;

    int one_side_max(TreeNode* root)
    {
        if ( root == nullptr )
        {
            return 0;
        }

        int left = std::max(0, one_side_max(root->left));
        int right = std::max(0, one_side_max(root->right));
        ans = std::max(ans, left + right + root->val);
        return std::max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root)
    {
        one_side_max(root);
        return ans;
    }
};
// @lc code=end

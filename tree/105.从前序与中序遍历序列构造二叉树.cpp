/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

// typedef TreeNode;

class Solution
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for ( int i = 0; i < inorder.size(); i++ )
        {
            inorder_idx[inorder[i]] = i;
        }
        return buildNode(preorder, 0, preorder.size() - 1,
                         inorder, 0, inorder.size() - 1);
    }

private:
    unordered_map<int, int> inorder_idx;

    TreeNode* buildNode(vector<int>& preorder, int pre_beg, int pre_end,
                        vector<int>& inorder, int in_beg, int in_end)
    {
        if ( pre_beg > pre_end || in_beg > in_end )
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode();
        node->val      = preorder[pre_beg];

        int cur_pos   = inorder_idx[node->val];
        int nums_left = cur_pos - in_beg;

        node->left  = buildNode(preorder, pre_beg + 1, pre_beg + nums_left,
                               inorder, in_beg, cur_pos - 1);
        node->right = buildNode(preorder, pre_beg + nums_left + 1, pre_end,
                                inorder, cur_pos + 1, in_end);
        return node;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <deque>
#include <vector>

using namespace std;

class TreeNode;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;

        deque<TreeNode*> cur_nodes;
        deque<TreeNode*> child_nodes;
        vector<int>      level_vals;

        if ( root )
        {
            cur_nodes.push_back(root);
        }

        while ( !cur_nodes.empty() )
        {
            TreeNode* cur_node = cur_nodes.front();
            cur_nodes.pop_front();

            level_vals.push_back(cur_node->val);

            if ( cur_node->left )
            {
                child_nodes.push_back(cur_node->left);
            }

            if ( cur_node->right )
            {
                child_nodes.push_back(cur_node->right);
            }

            if ( cur_nodes.empty() )
            {
                result.push_back(level_vals);
                level_vals.clear();
                cur_nodes.swap(child_nodes);
            }
        }

        return result;
    }
};
// @lc code=end

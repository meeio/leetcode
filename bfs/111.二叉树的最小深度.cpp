/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

#include <queue>

using namespace std;

class TreeNode;

class Solution
{
public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        queue<TreeNode*> to_visit;

        to_visit.push(root);
        int depth = 1;

        while ( !to_visit.empty() )
        {
            int sz = to_visit.size();
            for ( int i = 0; i < sz; i++ )
            {
                TreeNode* cur_node = to_visit.front();
                to_visit.pop();

                bool has_left  = cur_node->left != nullptr;
                bool has_right = cur_node->right != nullptr;

                if ( !has_left && !has_right )
                {
                    return depth;
                }

                if ( has_left )
                {
                    to_visit.push(cur_node->left);
                }

                if ( has_right )
                {
                    to_visit.push(cur_node->right);
                }
            }

            depth += 1;
        }

        return depth;
    }
};
// @lc code=end

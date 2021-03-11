/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 *
 * [1530] 好叶子节点对的数量
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

#include <vector>

using namespace std;

class TreeNode;

class Solution
{
public:
    int countPairs(TreeNode* root, int distance)
    {
        node_to_leaf_dis(root, distance);
        return ans;
    }

private:
    int ans;

    vector<int> node_to_leaf_dis(TreeNode* node, int max_dis)
    {
        if ( node == nullptr )
        {
            return {};
        }

        if ( !node->left && !node->right )
        {
            return {0};
        }

        vector<int> ret;

        vector<int> left_leaf_dis  = node_to_leaf_dis(node->left, max_dis);
        vector<int> right_leaf_dis = node_to_leaf_dis(node->right, max_dis);

        for ( int& i : left_leaf_dis )
        {
            i += 1;
            if ( i < max_dis )
            {
                ret.push_back(i);
            }
        }

        for ( int& i : right_leaf_dis )
        {
            i += 1;
            if ( i < max_dis )
            {
                ret.push_back(i);
            }
        }

        for ( int& i : left_leaf_dis )
        {
            for ( int& j : right_leaf_dis )
            {
                ans += ( i + j <= max_dis );
            }
        }

        return ret;
    }
};
// @lc code=end

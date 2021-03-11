/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
#include <algorithm>
#include <vector>

using namespace std;

class TreeNode;

class Solution
{
public:
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        auto pre1 = preorder(s);
        auto pre2 = preorder(t);

        return pre1.end() != search(pre1.begin(), pre1.end(), pre2.begin(), pre2.end());
    }

    vector<int> preorder(TreeNode* node)
    {
        if ( node == nullptr )
        {
            return {-9999};
        }

        vector<int> ret;

        auto left = preorder(node->left);
        auto right = preorder(node->right);

        ret.push_back(node->val);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.insert(ret.end(), right.begin(), right.end());

        return ret;
    }
    
};

// @lc code=end

/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
typedef TreeNode;
class Solution {
public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }

private:
    TreeNode* node1;
    TreeNode* node2;
    TreeNode* pre_node;

    void traverse(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        traverse(node->left);

        if (pre_node != nullptr && node->val < pre_node->val)
        {
            node1 = node1 == nullptr ? pre_node : node1;
            node2 = node;
        }

        pre_node = node;
        traverse(node->right);
    }
};
// @lc code=end


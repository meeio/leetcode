/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isSubStructure(TreeNode* A, TreeNode* B)
    {
        if(A == nullptr || B == nullptr) return false;

        return same_from_root(A, B)
               || isSubStructure(A->left, B)
               || isSubStructure(A->right, B);
    }

    bool same_from_root(TreeNode* t, TreeNode* p)
    {
        if ( p == nullptr )
        {
            return true;
        }

        if ( t == nullptr || t->val != p->val )
        {
            return false;
        }

        return same_from_root(t->left, p->left)
               && same_from_root(t->right, p->right);
    }
};
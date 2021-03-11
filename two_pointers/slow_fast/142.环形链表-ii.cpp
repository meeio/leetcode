/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNode;

class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        bool found = false;
        while ( fast != nullptr && fast->next != nullptr )
        {
            slow = slow->next;
            fast = fast->next->next;

            if ( slow == fast )
            {
                found = true;
                break;
            }
        }

        if ( found )
        {
            slow = head;
            while ( slow != fast )
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        else
        {
            return nullptr;
        }
    }
};
// @lc code=end

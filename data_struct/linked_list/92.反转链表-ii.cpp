/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ListNode;

class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if ( left == 1 )
        {
            return reverseN(head, right);
        }
        else
        {
            head->next = reverseBetween(head->next, left - 1, right - 1);
            return head;
        }
    }

private:
    ListNode* succecor;

    ListNode* reverseN(ListNode* head, int n)
    {
        if ( n == 1 )
        {
            printf("aaaaa");
            succecor = head->next;
            printf("bbbbb");
            return head;
        }
        else
        {
            ListNode* last = reverseN(head->next, n - 1);
            head->next->next = head;
            head->next       = succecor;

            return last;
        }
    }
};
// @lc code=end

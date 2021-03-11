/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode* tail = head;
        for (int count = 0; count < k; count++)
        {
            if (tail == nullptr)
            {
                return head;
            }
            tail = tail->next;
        }

        ListNode* new_head = reverseBetween(head, tail);
        head->next = reverseKGroup(tail, k);
        return new_head;
    }


private:
    ListNode* reverseBetween(ListNode* beg, ListNode* end)
    {

        ListNode* pre = nullptr;
        ListNode* cur = beg;
        ListNode* nxt = beg->next;

        while ( cur != end )
        {
            nxt = cur->next;
            cur->next = pre;

            pre = cur;
            cur = nxt;
        }
        

        return pre;
    }
};
// @lc code=end

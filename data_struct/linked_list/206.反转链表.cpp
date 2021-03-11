/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // ListNode* reverseList(ListNode* head)
    // {
    //     if (head == nullptr || head->next == nullptr)
    //     {
    //         return head;
    //     }
    //     else
    //     {
    //         ListNode* ret = reverseList(head->next);
    //         head -> next -> next = head;
    //         head -> next = nullptr;
    //         return ret;
    //     }
    // }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* slow = nullptr;
        ListNode* fast = head;

        while (fast != nullptr)
        {
            ListNode* next_fast = fast->next;
            fast->next = slow;

            slow = fast;
            fast = next_fast;
        }

        return slow;
    }
};
// @lc code=end

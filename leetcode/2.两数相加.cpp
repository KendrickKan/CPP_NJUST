/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int jin = 0;
        // ListNode *head;
        ListNode *ans;
        ListNode head;
        ans = &head;
        while (l1 || l2 || jin)
        {
            if (l1)
            {
                jin += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                jin += l2->val;
                l2 = l2->next;
            }
            ans->next = new ListNode(jin % 10);
            jin /= 10;
            ans = ans->next;
        }
        return head.next;
    }
};
// @lc code=end

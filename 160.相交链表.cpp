/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // method-1: link B in A's end, and judge whether have ring in entire link
        ListNode* result = nullptr;
        ListNode* tailA = headA;
        while(tailA->next != nullptr) {
            tailA = tailA->next;
        }
        tailA->next = headB;
        ListNode* fast = headA;
        ListNode* slow = headA;
        while(fast != nullptr && ) {

        }

        tailA->next = nullptr;
        return result;
    }
};
// @lc code=end


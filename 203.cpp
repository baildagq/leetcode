#include "./utils.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};

class Solution {
public:
    /*
    // method-1: self
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* sentinel = new ListNode(10);
        sentinel.next = head;
        ListNode* tail = sentinel;
        while (tail != nullptr) {
            if (tail->next == nullptr || tail->next->val == val) {
                tail = tail->next;
            } else {
                if (tail->next->next != nullptr) {
                    tail->next = tail->next->next;
                } else {
                    tail->next = nullptr;
                }
            }
        }
        return sentinel->next;
    }
    */

    // method-2: leetcode题解，感觉更加自然
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* sentinel = new ListNode(10);
        sentinel->next = head;
        ListNode* prev = sentinel;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            } 
            curr = curr->next;
        } 
        return sentinel->next;
    }
};

int main(int argc, const char** argv)
{
    ListNode* head = new ListNode(1);
    Solution().removeElements(head, 1);
    return 0;
}

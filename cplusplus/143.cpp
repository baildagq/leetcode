#include "./utils.h"

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
class Solution {
public:
    void reorderList(ListNode* head)
    {

        int len = 0;
        ListNode* tail = head;
        while (tail != nullptr) {
            len += 1;
            tail = tail->next;
        }
        if (len == 0 || len == 1) return;
        tail = head;
        for (int i = 0; i < ((len % 2 == 0) ? len / 2 - 1 : len / 2); i++) {
            tail = tail->next;
        }
        // reverse the second-half of list
        ListNode* newhead = tail->next;;
        tail->next = nullptr;
        tail = newhead->next;
        newhead->next = nullptr;
        while (tail != nullptr) {
            ListNode* node = tail;
            tail = tail->next;
            node->next = newhead;
            newhead = node;
        }
        // merge the first-half and reversed second-half list
        ListNode* res = new ListNode();
        tail = res;
        while (head != nullptr || newhead != nullptr) {
            if (head != nullptr) {
                tail->next = head;
                head = head->next;
                tail = tail->next;
                tail->next = nullptr;
            }
            if (newhead != nullptr) {
                tail->next = newhead;
                newhead = newhead->next;
                tail = tail->next;
                tail->next = nullptr;
            }
        }
        head = res->next;
    }
};

int main(int argc, const char** argv)
{
    ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);
    printListNodes(head);
    Solution().reorderList(head);
    printListNodes(head);
    delete head;
    return 0;
}

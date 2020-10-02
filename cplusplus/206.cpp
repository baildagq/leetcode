#include "./utils.h"


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* sentinel = nullptr;
        while (head != nullptr) {
            ListNode* node = new ListNode(head->val);
            node->next = sentinel;
            sentinel = node;
            head = head->next;
        }
        return sentinel;
    }
};


int main(int argc, const char** argv)
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    printListNodes(head);
    ListNode* res = Solution().reverseList(head); 
    printListNodes(res);
    return 0;
}

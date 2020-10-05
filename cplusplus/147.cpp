#include "./utils.h"



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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;
        ListNode* res = new ListNode(0);
        while (curr != nullptr) {
            ListNode* place = res;
            // 找到插入位置的前一个节点
            while(place->next != nullptr && place->next->val < curr->val) {
                place = place->next;
            }
            // 找到插入位置的后一个节点
            ListNode* tmp = nullptr;
            if (place->next != nullptr) {
                tmp = place->next;
            }
            // 插入节点
            place->next = curr;
            curr = curr->next;
            place->next->next = tmp;
        }
        return res->next;
    }
};


int main(int argc, const char** argv)
{
    // vector<int> list = {2,3,-2,4};
    // printf("res: %d\n", Solution().xxx(list));
    return 0;
}

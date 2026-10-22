#include <common.h>
class Solution {
   public:
   
    // 翻转链表;
    ListNode* reverseList(ListNode* head) {
        ListNode new_head;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = new_head.next;
            new_head.next = cur;
            cur = tmp;
        }
        return new_head.next;
    }

    // K组 翻转一次;
    ListNode* reverseKGroup(ListNode* head, int k) {
        
    }
};
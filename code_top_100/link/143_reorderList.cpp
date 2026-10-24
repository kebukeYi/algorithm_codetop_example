#include <common.h>
class Solution {
   public:
    // 重排链表
    void reorderList(ListNode* head) {
        // slow 停的是「前半段最后一个节点」
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow->next;
        // 断开链表;
        slow->next = nullptr;

        ListNode* pre = nullptr;
        while (middle) {
            auto nex = middle->next;
            middle->next = pre;
            pre = middle;
            middle = nex;
        }

        // 1 2 3 4 5 6 7 slow: 4
        // 1 2 3 4 7 6 5
        // 1 2 3 4 5 6  slow: 3
        //
        // pre
        // cur
        auto cur = head;
        while (pre) {
            ListNode* t = pre->next;
            pre->next = cur->next;
            cur->next = pre;

            cur = pre->next;
            pre = t;
        }
    }
};
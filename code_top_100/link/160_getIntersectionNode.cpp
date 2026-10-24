#include <common.h>
class Solution {
   public:
    // 相交链表; 两个节点走的是相同步数, 一步一步的走;
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        //
        while (p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }

        return q;
    }
};
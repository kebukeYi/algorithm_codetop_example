#include <common.h>
class Solution {
   public:
    // 给你一个链表，两两交换其中相邻的节点，
    // 并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）
    // k 个一组进行反转; k=2;
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* node0 = &dummy;
        ListNode* node1 = head;
        // 0 1 2 3 4 5
        while (node1 && node1->next) {
            ListNode* node2 = node1->next;
            ListNode* node3 = node2->next;
            node0->next = node2;
            node2->next = node1;
            node1->next = node3;

            node0 = node1;
            node1 = node3;
        }
        return dummy.next;
    }
};
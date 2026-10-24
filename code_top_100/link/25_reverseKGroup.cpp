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
        int n = 0;
        ListNode* tmp = head;
        // 总共有多少个节点;
        while (tmp != nullptr) {
            n++;
            tmp = tmp->next;
        }

        ListNode dummy(0, head);
        ListNode* group_last_tail = &dummy;

        // 走几组;
        for (; n >= k; n -= k) {
            
            // 每组进行反转;
            ListNode* pre = nullptr;
            ListNode* cur = group_last_tail->next;
            for (int i = 0; i < k; i++) {
                ListNode* nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }

            // 翻转前: tail  end  pre
            // 翻转后: tail  pre  end  cur
            // cur : 下一组的要翻转起始点
            // pre : 翻转后组的 新起点
            // group_last_tail : 相当于上一组的尾节点
            // group_last_tail.next : 当前翻转后新组的尾节点
            ListNode* end = group_last_tail->next;
            end->next = cur;              // 当前组的尾节点指向下一组的起始节点
            group_last_tail->next = pre;  // 上一组的尾节点指向当前组的头节点
            group_last_tail = end;
        }
        return dummy.next;
    }
};
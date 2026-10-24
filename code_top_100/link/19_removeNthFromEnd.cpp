#include <common.h>
class Solution {
   public:
    // 删除链表中 正数第K个节点;
    ListNode* removeNthFromStart(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        int i = 0;
        ListNode dummy(0, head);
        ListNode* pre = &dummy;

        ListNode* slow = pre;
        ListNode* fast = pre->next;
        i++;
        // [dummy,1,2] n=1;
        while (i != n) {
            if (slow == nullptr || fast == nullptr) return head;  // 越界保护
            slow = slow->next;
            fast = fast->next;
            i++;
        }
        if (fast == nullptr) return head;  // n 超长
        // i = n
        slow->next = fast->next;
        return dummy.next;
    }

    // 删除链表中 正数第K个节点, 单指针版;
    ListNode* removeNthFromStart(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        for (int i = 1; i < n && prev->next; ++i) {
            prev = prev->next;
        }
        // 确认第 n 个节点存在
        if (prev->next) {
            prev->next = prev->next->next;
        }
        return dummy.next;
    }

    // 删除链表中 倒数第K个节点; fast 多跑 n+1 步;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // fast 先跑 n+1 步
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // 快慢 一直跑;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy.next;
    }

    // 输入一个链表，输出该链表中倒数第k个节点
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (k--) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
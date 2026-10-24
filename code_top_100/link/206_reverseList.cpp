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

    /*
    给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right
    请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表;
    */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 重新建立一个实体哨兵节点;
        ListNode dummy(0, head);
        ListNode* p0 = &dummy;

        // 找到 要翻转组节点的前一个节点;
        for (int i = 0; i < left - 1; i++) {
            p0 = p0->next;
        }

        // 进行 限定值的翻转;
        // 1 -> 2 -> 3 -> 4 -> 5
        // 1 -> 4 -> 3 -> 2 -> 5
        ListNode* pre = nullptr;
        ListNode* cur = p0->next;
        for (int i = 0; i < right - left + 1; i++) {
            auto nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }

        // left.next = right
        p0->next->next = cur;
        p0->next = pre;
        return dummy.next;
    }
};
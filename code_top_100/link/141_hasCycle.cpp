#include <common.h>
class Solution {
   public:
    // 判断是否是环形链表;
    // 快慢指针: 总有相交的时刻, 不一定在环的入口处相交;
    // 否则 快指针先到达 终点 null;
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            head = head->next;
            fast = fast->next->next;
            if (fast == head) {
                return true;
            }
        }
        return false;
    }

    // 给定一个链表的头节点 head, 返回链表开始入环的第一个节点;
    // 如果链表无环，则返回 null;
    ListNode* hasCycle2(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            // 快慢指针相遇;
            if (fast == slow) {
                ListNode* ans = head;
                while (ans != slow) {
                    ans = ans->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
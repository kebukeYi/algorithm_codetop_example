#include <common.h>

#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    // 排序链表, 分治思想;
    // 找到链表的中间节点, 一分为二;
    // 合并两个有序链表;
    // 分治, 分解;

    // 找到中间节点, 并断链表;
    ListNode* middleNode(ListNode* head) {
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            pre = slow;               // 记录当前节点;
            slow = slow->next;        // 中间节点;
            fast = fast->next->next;  // 相同距离, 速度快1倍;
        }
        pre->next = nullptr;
        return slow;
    }

    ListNode* megerList(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        // 如果链表为空或者只有一个节点，无需排序
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 找到中间节点 head2，并断开 head2 与其前一个节点的连接
        // 比如 head=[4,2,1,3]，那么 middleNode 调用结束后 head=[4,2]
        // head2=[1,3]
        auto middle = middleNode(head);
        // 分治
        auto left = sortList(head);
        auto right = sortList(middle);
        // 合并
        auto new_head = megerList(left, right);
        return new_head;
    }
};

int main() {}
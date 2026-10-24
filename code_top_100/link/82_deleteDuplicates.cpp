#include <common.h>

#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    // 删除链表的重复元素,保留一个;
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }



    // 删除链表的所有重复元素, 有可能删除头节点;
    ListNode* deleteDuplicates2(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* pre = &dummy;
        ListNode* cur = dummy.next;
        while (cur) {
            // 一直遍历到 重复段的最后一个节点;
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }

            // 判断是否 跳过了某些节点;
            if (pre->next == cur) {
                pre = cur;
            } else {
                pre->next = cur->next;
            }

            cur = cur->next;
        }
        return dummy.next;
    }
};

int main() {}
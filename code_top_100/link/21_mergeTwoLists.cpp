#include <common.h>

#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {

    // 合并两个有序链表;
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* p = &dummy;

        while (list1 != nullptr || list2 != nullptr) {
            if (list2 == nullptr ||
                (list1 != nullptr && list1->val < list2->val)) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        return dummy.next;
    }
};
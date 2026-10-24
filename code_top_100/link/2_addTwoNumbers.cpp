

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    // 原地修改方案;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // l1 5 6 7
        // l2 6 8 9
        // l2 1 5
        ListNode* dummy = l2;
        ListNode* pre = l2;
        // 阶段 1：两链表都有节点
        while (l1 && l2) {
            auto l1val = l1->val;
            auto l2val = l2->val;
            auto val = l1val + l2val + carry;
            carry = val / 10;
            l2->val = val % 10;

            pre = l2;
            l1 = l1->next;
            l2 = l2->next;
        }

        // 阶段 2：l1 耗尽，l2 还有剩余 —— 只需在 l2 上传播进位
        while (l2) {
            if (carry == 0) {
                break;
            }
            auto val = l2->val + carry;
            carry = val / 10;
            l2->val = val % 10;
            pre = l2;
            l2 = l2->next;
        }

        // 阶段 3：l2 耗尽，l1 还有剩余 —— 无条件接上，再传播进位
        if (l1) {
            // 关键：无条件接
            pre->next = l1;
            // 只有存在进位, 才回去改变数值;
            while (carry && l1) {
                auto l1val = l1->val;
                auto val = l1val + carry;
                carry = val / 10;
                l1->val = val % 10;
                pre = l1;
                l1 = l1->next;
            }
        }

        if (carry) {
            ListNode* tail = new ListNode(carry);
            pre->next = tail;
        }

        return dummy;
    }

    // 新链表方案
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        int carry = 0;
        ListNode* cur = &dummy;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        return dummy.next;
    }
};
struct ListNode {
    ListNode* next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int a) : val(a), next(nullptr) {}
    ListNode(int a, ListNode* x) : val(a), next(x) {}
};

class Solutiin {
   public:
    // 判断链表是否是回文串;
    // 1. 把链表转为 数组, 然后从前往后和从后往前判断;
    // 2. 递归
    // 3. 找到中间节点, 然后翻转链表, 然后再进行判断;
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;  // 空 / 单节点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 偶数: n/2+1    下一段节点的第一个节点;
        // 奇数: (n+1)/2  中间节点;
        ListNode* pre = nullptr;
        ListNode* cur = slow;
        while (cur) {
            auto nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }

        while (pre) {
            // 3	3（head 走到中间）	✓ 同一个节点自己比自己
            if (pre->val != head->val) {
                return false;
            }
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
};
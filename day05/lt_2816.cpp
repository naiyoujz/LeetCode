//
// Created by xili on 2024/7/28 21:16.
// Go big or go home.
//

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *doubleIt(ListNode *head) {
        head = reverse(head);
        ListNode *p = head;
        int carry = 0;
        int t = 0;
        while (p->next) {
            t = p->val;
            p->val = (2 * t) % 10 + carry;
            carry = (2 * t) / 10;
            p = p->next;
        }
        t = p->val;
        p->val = (2 * t) % 10 + carry;
        carry = (2 * t) / 10;
        ListNode *node = new ListNode(carry);
        if (carry) {
            p->next = node;
        } else {
            p->next = nullptr;
        }
        return reverse(head);
    }

    ListNode *reverse(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
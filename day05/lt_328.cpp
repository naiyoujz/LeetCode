//
// Created by xili on 2024/7/28 18:35.
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
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *evenHead = head->next;
        ListNode *even = evenHead;
        ListNode *odd = head;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
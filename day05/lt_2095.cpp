//
// Created by xili on 2024/7/28 20:39.
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
    ListNode *deleteMiddle(ListNode *head) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *slow = dummyHead;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};
//
// Created by xili on 2024/7/28 17:49.
// Go big or go home.
//


using namespace std;

#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        vector<int> help;
        int sum = 0;
        ListNode *p = head->next;
        while (p) {
            if (p->val == 0) {
                help.push_back(sum);
                sum = 0;
            }
            sum += p->val;
            p = p->next;
        }
        ListNode *dummyHead = new ListNode;
        p = dummyHead;
        for (auto &item: help) {
            ListNode *node = new ListNode(item);
            p->next = node;
            p = node;
        }
        return dummyHead->next;
    }
};

//
// Created by xili on 2024/7/28 16:37.
// Go big or go home.
//

using namespace std;

#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *p = head;
        vector<int> v;
        while (p) {
            v.push_back(p->val);
            p = p->next;
        }
        sort(v.begin(), v.end());
        p = head;
        int i = 0;
        while (p) {
            p->val = v[i++];
            p = p->next;
        }
        return head;
    }
};
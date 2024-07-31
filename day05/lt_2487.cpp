//
// Created by xili on 2024/7/28 21:02.
// Go big or go home.
//
#include <stack>
#include <vector>
#include <algorithm>

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
    ListNode *removeNodes(ListNode *head) {
        stack<int> s;
        vector<int> v;
        ListNode *p = head;
        while (p) {
            while (!s.empty() && p->val > s.top()) {
                s.pop();
            }
            s.push(p->val);
            p = p->next;
        }
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(), v.end());
        p = head;
        for (int i = 0; i < v.size() - 1; i++) {
            p->val = v[i];
            p = p->next;
        }
        p->val = v[v.size() - 1];
        p->next = nullptr;
        return head;
    }
};
//
// Created by xili on 2024/7/28 19:28.
// Go big or go home.
//
#include <vector>
#include <stack>

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
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> ans;
        ListNode *p = head;
        while (p) {
            ans.push_back(p->val);
            p = p->next;
        }
        //严格小压大
        stack<int> s;
        for (int i = 0; i < ans.size(); i++) {
            while (!s.empty() && ans[i] > ans[s.top()]) {
                ans[s.top()] = ans[i];
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            ans[s.top()] = 0;
            s.pop();
        }
        return ans;
    }
};
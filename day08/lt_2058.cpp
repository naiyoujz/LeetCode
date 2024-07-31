//
// Created by xili on 2024/7/31 10:56.
// Go big or go home.
//
#include <vector>
#include <climits>

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
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        ListNode *pre = head;
        ListNode *cur = head->next;
        int index = 1, left = -1, right = -1;
        int mx = -1, mn = INT_MAX;
        while (cur->next) {
            if ((cur->val > pre->val && cur->val > cur->next->val) ||
                (cur->val < pre->val && cur->val < cur->next->val)) {
                if (left == -1) {
                    left = index;
                    right = index;
                } else {
                    mn = min(mn, index - right);
                    mx = index - left;
                    right = index;
                }
            }
            index++;
            pre = pre->next;
            cur = cur->next;
        }
        if (mx == -1) {
            return {-1, -1};
        }
        return {mn, mx};
    }
};
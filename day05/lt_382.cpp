//
// Created by xili on 2024/7/28 20:29.
// Go big or go home.
//
#include <vector>
#include <cstdlib>

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
    vector<int> ans;

    Solution(ListNode *head) {
        while (head) {
            ans.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        return ans[rand() % ans.size()];
    }
};
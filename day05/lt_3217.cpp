//
// Created by xili on 2024/7/28 21:34.
// Go big or go home.
//
#include <vector>
#include <unordered_set>

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
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        unordered_set<int> us;
        for (auto &item: nums) {
            us.insert(item);
        }
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *slow = dummyHead;
        ListNode *fast = head;
        while (fast) {
            if (!us.count(fast->val)) {
                slow->next = fast;
                slow = fast;
            }
            fast = fast->next;
        }
        slow->next = fast;
        return dummyHead->next;
    }
};
//
// Created by xili on 2024/7/27 18:25.
// Go big or go home.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string> &operations) {
        stack<int> s;
        for (auto &item: operations) {
            if (item == "+") {
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.push(top1);
                s.push(top1 + top2);
            } else if (item == "D") {
                s.push(2 * s.top());
            } else if (item == "C") {
                s.pop();
            } else {
                s.push(stoi(item));
            }
        }
        int ans = 0;
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};

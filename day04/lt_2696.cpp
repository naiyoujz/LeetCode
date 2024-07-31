//
// Created by xili on 2024/7/27 21:02.
// Go big or go home.
//
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> c;
        for (auto &item: s) {
            if (!c.empty() && ((item == 'B' && c.top() == 'A') || (item == 'D' && c.top() == 'C'))) {
                c.pop();
                continue;
            }
            c.push(item);
        }
        return c.size();
    }
};
//
// Created by xili on 2024/7/27 19:38.
// Go big or go home.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return res(s).compare(res(t)) == 0;
    }

    string res(string &r) {
        stack<char> c;
        for (auto &item: r) {
            if (item == '#' && !c.empty()) {
                c.pop();
            } else if (item != '#') {
                c.push(item);
            }
        }
        int rsize = 0;
        while (!c.empty()) {
            r[rsize++] = c.top();
            c.pop();
        }
        return r.substr(0, rsize);
    }
};
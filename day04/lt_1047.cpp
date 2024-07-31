//
// Created by xili on 2024/7/27 19:17.
// Go big or go home.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> cs;
        for (auto &item: s) {
            //栈不为空，且当前元素等于栈顶元素
            if (!cs.empty() && item == cs.top()) {
                cs.pop();
                continue;
            }
            //栈为空或者当前元素不等于栈顶元素，直接入栈
            cs.push(item);
        }
        int returnSize = 0;
        //将栈中元素弹出从尾开始插入s中
        while (!cs.empty()) {
            s[s.size() - 1 - returnSize++] = cs.top();
            cs.pop();
        }
        //返回s的子串
        return s.substr(s.size() - returnSize, s.size());
    }
};
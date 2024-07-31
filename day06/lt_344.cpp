//
// Created by xili on 2024/7/29 21:30.
// Go big or go home.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//转化成字符串，翻转后替换s
class Solution1 {
public:
    void reverseString(vector<char> &s) {
        string ans = "";
        for (auto &item: s) {
            ans += item;
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        for (auto &item: ans) {
            s[i++] = item;
        }
    }
};

//直接翻转
class Solution {
public:
    void reverseString(vector<char> &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};
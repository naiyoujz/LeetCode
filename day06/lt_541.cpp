//
// Created by xili on 2024/7/29 21:43.
// Go big or go home.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};

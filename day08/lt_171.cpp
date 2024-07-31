//
// Created by xili on 2024/7/31 13:32.
// Go big or go home.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (auto &item: columnTitle) {
            ans = ans * 26 + item - 'A' + 1;
        }
        return ans;
    }
};
//
// Created by xili on 2024/7/31 16:27.
// Go big or go home.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int count0 = 0;
        int count1 = 0;
        int ans = 0;
        for (auto &item: s) {
            count1 += item == '1' ? 1 : 0;
        }
        if (count1 == 0 || count1 == s.size()) {
            return s.size() - 1;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            s[i] == '0' ? count0++ : count1--;
            ans = max(ans, count0 + count1);
        }
        return ans;
    }
};
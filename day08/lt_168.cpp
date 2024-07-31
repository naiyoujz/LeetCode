//
// Created by xili on 2024/7/31 11:33.
// Go big or go home.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            int temp = (columnNumber - 1) % 26 + 1;
            ans += temp - 1 + 'A';
            columnNumber = (columnNumber - temp) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
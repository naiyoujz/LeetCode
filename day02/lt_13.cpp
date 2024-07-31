//
// Created by xili on 2024/7/25 14:29.
// Go big or go home.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int val = roman[s[i]];
            //当前值比下个值小，减去当前值，比下个值大，加上当前值
            if (i < n - 1 && val < roman[s[i + 1]]) {
                ans -= val;
            } else {
                ans += val;
            }
        }
        return ans;
    }
};

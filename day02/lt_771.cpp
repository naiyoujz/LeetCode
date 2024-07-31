//
// Created by xili on 2024/7/25 16:33.
// Go big or go home.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // 'A'=65   'z'=122
        vector<int> help(58, 0);
        for (auto &ele: jewels) {
            help[ele - 'A']++;
        }
        int ans=0;
        for (auto &ele: stones) {
            ans += help[ele - 'A'] > 0 ? 1 : 0;
        }
        return ans;
    }
};
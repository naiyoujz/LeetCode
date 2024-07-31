//
// Created by xili on 2024/7/30 20:37.
// Go big or go home.
//
#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size() > word2.size() ? word1.size() : word2.size();
        string ans;
        for (int i = 0; i < n; i++) {
            if (i < word1.size()) {
                ans += word1[i];
            }
            if (i < word2.size()) {
                ans += word2[i];
            }
        }
        return ans;
    }
};
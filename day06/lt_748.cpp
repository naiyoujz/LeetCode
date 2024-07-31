//
// Created by xili on 2024/7/29 19:08.
// Go big or go home.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        int cnt[26]{};
        for (char c: licensePlate) if (isalpha(c)) ++cnt[tolower(c) - 'a'];
        stable_sort(begin(words), end(words), [](auto &&a, auto &&b) { return a.size() < b.size(); });
        for (auto &&s: words) {
            int cnt2[26]{}, flag = true;
            for (char c: s)if (isalpha(c)) ++cnt2[tolower(c) - 'a'];
            for (int i = 0; i < 26; ++i)
                if (cnt2[i] < cnt[i]) {
                    flag = false;
                    break;
                }
            if (flag) return s;
        }
        return "";
    }
};
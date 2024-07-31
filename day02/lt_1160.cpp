//
// Created by xili on 2024/7/25 13:49.
// Go big or go home.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string> &words, string chars) {
        int ans;
        unordered_map<char, int> c2n;
        //chars中各个字符的数量
        for (auto &ele: chars) {
            c2n[ele]++;
        }
        for (auto &s: words) {
            unordered_map<char, int> w2n;
            //words中单个字符换的字符数量
            for (auto &c: s) {
                w2n[c]++;
            }
            bool isans = true;
            //比较字符串的数量大小
            for (auto &c: s) {
                if (c2n[c] < w2n[c]) {
                    isans = false;
                    break;
                }
            }
            if (isans) {
                ans += s.size();
            }
        }
        return ans;
    }
};

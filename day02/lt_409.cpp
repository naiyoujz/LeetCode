//
// Created by xili on 2024/7/25 14:48.
// Go big or go home.
//
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> s2n;
        //将每个元素的个数存入map中
        for (auto &ele: s) {
            s2n[ele]++;
        }
        int ans = 0;
        //看是否有元素的个数是奇数
        bool haveEven = false;
        //遍历map，如果是奇数，减1后加到ans，如果是偶数，直接加
        for (auto ele: s2n) {
            if (ele.second & 1) {
                haveEven = true;
                ans -= 1;
            }
            ans += ele.second;
        }
        //有奇数，答案为所有元素的偶数和加1
        return haveEven ? ans + 1 : ans;
    }
};

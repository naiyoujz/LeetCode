//
// Created by xili on 2024/7/25 11:22.
// Go big or go home.
//
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < s.size(); i++) {
            char x = s[i];
            char y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && s2t[y] != x))
                return false;
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};
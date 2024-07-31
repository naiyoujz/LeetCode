//
// Created by xili on 2024/7/25 11:22.
// Go big or go home.
//
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //pattern = "abba", s = "dog cat cat dog"
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        int m = str.length();
        int i = 0;
        for (char &ele: pattern) {
            if (i >= m) {
                return false;
            }
            int j = i;
            while (j < m && str[j] != ' ') {
                j++;
            }
            const string &temp = str.substr(i, j - i);
            if (p2s.count(ele) && p2s[ele] != temp) {
                return false;
            }
            if (s2p.count(temp) && s2p[temp] != ele) {
                return false;
            }
            p2s[ele] = temp;
            s2p[temp] = ele;
            i = j + 1;
        }
        return i >= m;
    }
};
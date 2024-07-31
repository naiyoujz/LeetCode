//
// Created by xili on 2024/7/27 19:53.
// Go big or go home.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string result;
        for (char c : s) {
            if (!result.empty() && abs(result.back() - c) == 32) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};

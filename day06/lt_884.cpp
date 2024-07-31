//
// Created by xili on 2024/7/29 20:44.
// Go big or go home.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string ss = s1 + " " + s2;
        unordered_map<string, int> ump;
        for (int i = 0, j = 0; j < ss.size();) {
            string temp = "";
            while (ss[j] != ' ' && j < ss.size()) {
                j++;
            }
            ump[ss.substr(i, j - i)]++;
            j++;
            i = j;
        }
        vector<string> ans;
        for (auto &item: ump) {
            if (item.second == 1) {
                ans.emplace_back(item.first);
            }
        }
        return ans;
    }
};
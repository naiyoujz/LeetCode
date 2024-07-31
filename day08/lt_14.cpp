//
// Created by xili on 2024/7/31 8:55.
// Go big or go home.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//逐个匹配
class Solution1 {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (!strs[0].empty()) {
            return "";
        }
        string pre = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; i++) {
            pre = longestCommonPrefix(pre, strs[i]);
            if (!pre.empty()) {
                return "";
            }
        }
        return pre;
    }

    string longestCommonPrefix(string &s1, string &s2) {
        int n = min(s1.size(), s2.size());
        int len = 0;
        while (len < n && s1[len] == s2[len]) {
            len++;
        }
        return s1.substr(0, len);
    }
};

//排序字符串，比较第一个和最后一个
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        sort(strs.begin(), strs.end());
        string ans;
        int n = strs.size();
        int len = min(strs[0].size(), strs[n - 1].size());
        for (int i = 0; i < len; i++) {
            if (strs[0][i] == strs[n - 1][i]) {
                ans.push_back(strs[0][i]);
            } else {
                break;
            }
        }
        return ans;
    }
};
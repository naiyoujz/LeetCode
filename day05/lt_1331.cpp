//
// Created by xili on 2024/7/28 15:57.
// Go big or go home.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        unordered_map<int, int> um;
        vector<int> s = arr;
        vector<int> ans;
        sort(s.begin(), s.end());
        int i = 1;
        for (auto &item: s) {
            if (!um.count(item)) {
                um[item] = i++;
            }
        }
        for (auto &item: arr) {
            ans.push_back(um[item]);
        }
        return ans;
    }
};

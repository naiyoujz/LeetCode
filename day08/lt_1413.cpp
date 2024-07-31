//
// Created by xili on 2024/7/31 16:18.
// Go big or go home.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minStartValue(vector<int> &nums) {
        int ans = INT_MAX;
        int sumi = 0;
        for (auto &item: nums) {
            sumi += item;
            ans = min(ans, sumi);
        }
        return -ans + 1;
    }
};
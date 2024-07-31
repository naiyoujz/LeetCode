//
// Created by xili on 2024/7/31 17:06.
// Go big or go home.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        vector<int> ans;
        int sum = 0;
        for (auto &item: nums) {
            sum += item;
            ans.emplace_back(sum);
        }
        return ans;
    }
};
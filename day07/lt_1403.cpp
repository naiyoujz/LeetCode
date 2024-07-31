//
// Created by xili on 2024/7/30 13:57.
// Go big or go home.
//
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int> &nums) {
        sort(nums.begin(), nums.end(), cmp);
        vector<int> ans;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sumAns = 0;
        int i = 0;
        for (; i < nums.size(); i++) {
            if (sumAns > sum) {
                break;
            }
            sumAns += nums[i];
            sum -= nums[i];
            ans.emplace_back(nums[i]);
        }
        return ans;
    }

    bool cmp(int a, int b) {
        return a > b;
    }
};

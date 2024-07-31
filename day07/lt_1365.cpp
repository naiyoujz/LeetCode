//
// Created by xili on 2024/7/30 15:23.
// Go big or go home.
//
#include <vector>

using namespace std;

// 计数
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> counts(101, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            counts[nums[i]]++;
        }
        for (int i = 1; i < 101; i++) {
            counts[i] += counts[i - 1];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.emplace_back(nums[i] == 0 ? 0 : counts[nums[i] - 1]);
        }
        return ans;
    }
};

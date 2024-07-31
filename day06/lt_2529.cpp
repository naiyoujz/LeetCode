//
// Created by xili on 2024/7/29 10:36.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int> &nums) {
        int count1 = nums.size() - (upper_bound(nums.begin(), nums.end(), 0) - nums.begin());
        int count2 = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return max(count1, count2);
    }
};
//
// Created by xili on 2024/7/29 10:01.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 0, j = n - 1; i < j; i++) {
            while (i < j && nums[i] + nums[j] >= target) {
                j--;
            }
            ans += j - i;
        }
        return ans;
    }
};
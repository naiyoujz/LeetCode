//
// Created by xili on 2024/7/29 14:43.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countElements(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        while (l < nums.size() - 1 && nums[l + 1] == nums[l]) {
            l++;
        }
        while (r > 0 && nums[r - 1] == nums[r]) {
            r--;
        }
        return r - l - 1 > 0 ? r - l - 1 : 0;
    }
};
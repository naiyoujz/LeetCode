//
// Created by xili on 2024/7/26 14:29.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        //1.全是正数
        //2.全是负数
        //3.最后一位正数和前两位是负数
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};

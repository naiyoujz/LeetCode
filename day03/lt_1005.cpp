//
// Created by xili on 2024/7/26 15:19.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        // 对数组进行排序
        sort(nums.begin(), nums.end());
        // 遍历数组并进行取反操作
        for (int i = 0; i < nums.size() && nums[i] < 0 && k > 0; ++i, --k) {
            nums[i] = -nums[i];
        }
        // 如果 k 仍然大于 0 并且是奇数，需要对最小的元素再取反一次
        if (k % 2 == 1) {
            // 找到最小的元素
            int minElementIndex = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minElementIndex] = -nums[minElementIndex];
        }
        // 计算数组的和
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        return sum;
    }
};

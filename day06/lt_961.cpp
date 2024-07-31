//
// Created by xili on 2024/7/29 21:08.
// Go big or go home.
//
#include <vector>
#include <cstdlib>

using namespace std;

//随机选择
class Solution1 {
public:
    int repeatedNTimes(vector<int> &nums) {
        while (1) {
            int a = rand() % nums.size();
            int b = rand() % nums.size();
            if (a != b && nums[a] == nums[b]) {
                return nums[a];
            }
        }
    }
};

//摩尔投票
class Solution2 {
public:
    int repeatedNTimes(vector<int> &nums) {
        //去掉最后一位数
        int last = nums[nums.size() - 1];
        int counts = 0;
        int ret;
        for (int i = 0; i < nums.size() - 1; i++) {
            //如果出现了去除的数，直接返回该数
            if (nums[i] == last) {
                return last;
            }
            //进行摩尔投票，找出超过一半的数
            if (counts == 0) {
                ret = nums[i];
                counts++;
            } else {
                counts += ret == nums[i] ? 1 : -1;
            }
        }
        return ret;
    }
};
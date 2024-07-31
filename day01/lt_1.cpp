//
// Created by xili on 2024/7/25 11:22.
// Go big or go home.
//
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        //创建一个哈希表
        unordered_map<int, int> hashtable;
        //遍历nums
        for (int i = 0; i < nums.size(); i++) {
            //如果再哈希表中找到了target-num[i]的键，则返回当前nums下标和哈希表中的值
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            //将当前值和下标存入哈希表中
            hashtable[nums[i]] = i;
        }
        //没找到，返回空
        return {};
    }
};
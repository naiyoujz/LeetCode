//
// Created by xili on 2024/7/29 11:15.
// Go big or go home.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, int> um;
        for (auto &item: nums) {
            um[item]++;
        }
        auto i = max_element(um.begin(), um.end(), cmp_value);
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] != i->first) {
                l++;
            }
            if (nums[r] != i->first) {
                r--;
            }
            if (nums[l] == i->first && i->first == nums[r]) {
                break;
            }
        }
        return r - l + 1;
    }

    static bool cmp_value(const pair<int, int> left, const pair<int, int> right) {
        return left.second < right.second;
    }
};
*/
class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        // 定义统计哈希表和最大频数
        unordered_map<int, int> mp;
        int max_fre = 0;
        // 统计频数，并计算最大频数
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            max_fre = max(max_fre, mp[nums[i]]);
        }
        // 重构map
        mp.erase(mp.begin(), mp.end());
        // 定义窗口和满足频数的最短长度
        int ans = nums.size();
        int left = 0, right = 0;
        while (right < nums.size()) {
            mp[nums[right]]++;
            // 频数达到要求后，移动左边界
            while (mp[nums[right]] == max_fre) {
                ans = min(ans, right - left + 1);
                mp[nums[left++]]--;
            }
            right++;
        }
        return ans;
    }
};

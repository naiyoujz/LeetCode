//
// Created by xili on 2024/7/29 10:14.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

//二分查找
class Solution1 {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        int m;
        vector<int> ans;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] == target) {
                break;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (nums[m] != target) {
            return ans;
        }
        l = r = m;
        while (l > 0 && nums[l - 1] == target) {
            l--;
        }
        while (r < nums.size() - 1 && nums[r + 1] == target) {
            r++;
        }
        for (int i = l; i <= r; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};

//顺序查找
class Solution2 {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
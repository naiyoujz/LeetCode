//
// Created by xili on 2024/7/25 11:44.
// Go big or go home.
//
#include <vector>
#include <set>

using namespace std;

//nums = [4,3,2,7,8,2,3,1]
//ans = [5,6]
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        for (auto &ele: nums) {
            int x = (ele - 1) % n;
            nums[x] += n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

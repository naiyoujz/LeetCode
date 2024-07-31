//
// Created by xili on 2024/7/25 11:22.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

//对数组进行排序，看下标是否与其对应
class Solution1 {
public:
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int ele: nums) {
            if (ele != i) {
                return i;
            }
            i++;
        }
        return i;
    }
};

//异或
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int eorAll=0;
        int eorHas=0;
        for (int i = 0; i < nums.size(); i++) {
            eorAll ^= i;
            eorHas ^= nums[i];
        }
        eorAll ^= nums.size();
        return eorHas ^ eorAll;
    }
};
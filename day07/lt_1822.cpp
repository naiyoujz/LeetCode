//
// Created by xili on 2024/7/30 20:53.
// Go big or go home.
//
#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int> &nums) {
        int flag = 1;
        for (auto &item: nums) {
            if (item == 0) {
                return 0;
            }
            flag *= item > 0 ? 1 : -1;
        }
        return flag;
    }
};
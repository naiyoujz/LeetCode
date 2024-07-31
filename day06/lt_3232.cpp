//
// Created by xili on 2024/7/29 13:48.
// Go big or go home.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int> &nums) {
        int gw = 0;
        int sw = 0;
        int sum = 0;
        for (auto &item: nums) {
            sum += item;
            if (item > 0 && item < 10) {
                gw += item;
            }
            if (item > 9 && item < 100) {
                sw += item;
            }
        }
        return (gw > sum - gw) || (sw > sum - sw);
    }
};
//
// Created by xili on 2024/7/28 16:10.
// Go big or go home.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int max = 0, second = 0;
        for (auto &item: nums) {
            if (item > max) {
                second = max;
                max = item;
            } else if (item > second) {
                second = item;
            }
        }
        return (max - 1) * (second - 1);
    }
};
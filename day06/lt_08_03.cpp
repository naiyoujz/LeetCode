//
// Created by xili on 2024/7/29 9:30.
// Go big or go home.
//

using namespace std;

#include <vector>
#include <climits>

class Solution {
public:
    int findMagicIndex(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i) {
                return i;
            }
        }
        return -1;
    }
};
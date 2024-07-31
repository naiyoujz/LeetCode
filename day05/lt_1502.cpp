//
// Created by xili on 2024/7/28 16:16.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int val = arr[1] - arr[0];
        for (int i = 1, j = 2; j < arr.size(); i++, j++) {
            if (arr[j] - arr[i] != val) {
                return false;
            }
        }
        return true;
    }
};

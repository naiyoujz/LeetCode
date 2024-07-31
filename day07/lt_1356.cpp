//
// Created by xili on 2024/7/30 14:48.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int count1(int n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }

    vector<int> sortByBits(vector<int> &arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }

    static bool cmp(int a, int b) {
        return count1(a) == count1(b) ? a > b : count1(a) < count1(b);
    }
};

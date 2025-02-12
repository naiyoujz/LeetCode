//
// Created by xili on 2024/7/27 21:15.
// Go big or go home.
//
#include <vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2) {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                return nums1[i];
            }
        }
        return -1;
    }
};
//
// Created by xili on 2024/7/29 8:48.
// Go big or go home.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for (auto &item: arr1) {
            int low = item - d;
            int high = item + d;
            if (bSearch(arr2, low, high)) {
                ans++;
            }
        }
        return ans;
    }

    bool bSearch(vector<int> arr, int low, int high) {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] >= low && arr[m] <= high) {
                return false;
            } else if (arr[m] < low) {
                l = m + 1;
            } else if (arr[m] > high) {
                r = m - 1;
            }
        }
        return true;
    }
};

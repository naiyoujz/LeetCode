//
// Created by xili on 2024/7/30 20:29.
// Go big or go home.
//
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
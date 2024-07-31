//
// Created by xili on 2024/7/31 17:12.
// Go big or go home.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int> &gain) {
        int ans = -INT_MAX;
        int n = gain.size();
        for (int i = 1; i < n; i++) {
            ans = max(ans, gain[i - 1]);
            gain[i] += gain[i - 1];
        }
        return ans > gain[n - 1] ? ans : gain[n - 1];
    }
};
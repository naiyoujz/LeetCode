//
// Created by xili on 2024/7/26 15:49.
// Go big or go home.
//
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int minDif = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            if (diff < minDif) {
                ans.clear();
                minDif = diff;
                ans.push_back({arr[i], arr[i + 1]});
            } else if (diff == minDif) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};

//
// Created by xili on 2024/7/30 13:32.
// Go big or go home.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr) {
        unordered_map<int, int> ump;
        for (auto &item: target) {
            ump[item]++;
        }
        for (auto &item: arr) {
            ump[item]--;
        }
        for (auto &item: ump) {
            if (item.second != 0) {
                return false;
            }
        }
        return true;
    }
};

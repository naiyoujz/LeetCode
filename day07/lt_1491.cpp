//
// Created by xili on 2024/7/30 15:08.
// Go big or go home.
//
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

class Solution {
public:
    double average(vector<int> &salary) {
        double minS = INT_MAX;
        double maxS = -minS;
        double sum = 0;
        for (auto &item: salary) {
            minS = item < minS ? item : minS;
            maxS = item > maxS ? item : maxS;
            sum += item;
        }
        return (sum - minS - maxS) / (salary.size() - 2);
    }
};
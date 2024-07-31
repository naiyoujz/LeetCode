//
// Created by xili on 2024/7/25 11:22.
// Go big or go home.
//
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        //对糖果进行去重，比较去重后糖果的种类大小和她能吃的种类大小
        int canEat = candyType.size() / 2;
        int type = set<int>(candyType.begin(), candyType.end()).size();
        return canEat > type ? type : canEat;
    }
};
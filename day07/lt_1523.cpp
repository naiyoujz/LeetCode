//
// Created by xili on 2024/7/30 21:23.
// Go big or go home.
//

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        //都是偶数 (high-low)/2
        //都是奇数，或者一奇一偶 (high-low)/2+1
        return (high - low) / 2 + (!(high & 1) && !(low & 1) ? 0 : 1);
    }
};
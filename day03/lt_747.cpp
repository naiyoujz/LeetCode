//
// Created by xili on 2024/7/26 14:59.
// Go big or go home.
//
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int m=-1,n=-1;
        int index=0;
        for (int i = 0; i < nums.size(); i++) {
            //两种情况，需要调整
            //1.num[i]>m>n
            if(nums[i]>m){
                n=m;
                m=nums[i];
                index=i;
            }
            //2.m>num[i]>n
            else if(nums[i]>n){
                n=nums[i];
            }
        }
        return m>=2*n?index:-1;
    }
};
//
// Created by xili on 2024/7/26 8:45.
// Go big or go home.
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int>numSet;
        //将去重后的数组存入set集合中
        for(auto &item:nums){
            numSet.insert(item);
        }
        int cur;
        int len;
        int maxlen=0;
        for(auto &item:nums){
            //如果当前元素是开头元素，计算这个连续子序列的长度
            if(!numSet.count(item-1)){
                cur=item;
                len=1;
                //当子序列还在继续，就一直计算
                while (numSet.count(cur+1)){
                    cur+=1;
                    len+=1;
                }
                maxlen=maxlen>len?maxlen:len;
            }
        }
        return maxlen;
    }
};
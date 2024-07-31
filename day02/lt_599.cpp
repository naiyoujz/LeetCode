//
// Created by xili on 2024/7/25 15:09.
// Go big or go home.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        unordered_map<string, int> s2i;
        //记录list1中出现的字符串和下标
        for (int i = 0; i < list1.size(); i++) {
            s2i[list1[i]] = i;
        }
        vector<string> ans;
        int sumIndex = INT32_MAX;
        for (int i = 0; i < list2.size(); i++) {
            //看当前list2中的字符串在list中是否出现过
            if (s2i.count(list2[i]) > 0) {
                //获取该字符串在list1中的下标
                int j = s2i[list2[i]];
                //下标和比之前的小，把之前的字符串全部清除
                //把当前字符串添加到ans中
                if (i + j < sumIndex) {
                    ans.clear();
                    ans.push_back(list2[i]);
                    sumIndex = i + j;
                }
                //如果相等，直接加入到ans中
                else if (i + j == sumIndex) {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};
//
// Created by xili on 2024/7/25 16:04.
// Go big or go home.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        vector<string> ans;
        //将对应字母转化成行号
        //             ABCDEFGHIJKLMNOPQRSTUVWXYZ
        string rIdx = "12210111011122000010020202";
        for (auto &ele: words) {
            bool fond = true;
            //获取字符串首个字母的行号
            char index = rIdx[tolower(ele[0]) - 'a'];
            //遍历剩下的字母是否在当前行号
            for (int i = 1; i < ele.size(); i++) {
                //如果不在，将fond标为false,跳出
                if (rIdx[tolower(ele[i]) - 'a'] != index) {
                    fond = false;
                    break;
                }
            }
            //遍历结束后，都在同一行，将当前字符串加入到ans中
            if (fond) {
                ans.push_back(ele);
            }
        }
        return ans;
    }
};
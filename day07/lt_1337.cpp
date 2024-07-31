//
// Created by xili on 2024/7/30 14:21.
// Go big or go home.
//
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        multimap<int, int> m;  // 士兵数量 -> 行索引
        for (int i = 0; i < row; i++) {
            int soldiers = 0;
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1) {
                    soldiers++;
                } else {
                    break;  // 一旦遇到 0，跳出循环
                }
            }
            m.insert({soldiers, i});  // 插入士兵数量和行索引
        }
        vector<int> result;
        for (auto it = m.begin(); it != m.end() && result.size() < k; ++it) {
            result.push_back(it->second);  // 取出前 k 个最弱的行索引
        }
        return result;
    }
};

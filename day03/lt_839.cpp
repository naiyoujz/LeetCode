//
// Created by xili on 2024/7/26 8:56.
// Go big or go home.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> father;
    int sets;

    //构建集合
    void build(int n) {
        father.resize(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
        sets = n;
    }

    //寻找当前元素和所在集合的代表元素
    int find(int p) {
       if(p != father[p]) {
            father[p] = find(father[p]);
        }
        return father[p];
    }

    //判断x y是否在同一个集合
    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    //将x,y所在的集合合并
    void setUnion(int x, int y) {
        if (!isSameSet(x, y)) {
            father[find(x)] = find(y);
            sets--;
        }
    }

    int numSimilarGroups(vector<string> &strs) {
        //字符串数组的大小
        int l = strs.size();
        //单个字符串的大小
        int m = strs[0].size();
        build(l);
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                //如果x,y不在同一个集合内
                if (!isSameSet(i, j)) {
                    int diff = 0;
                    for (int k = 0; k < m && diff < 3; k++) {
                        if (strs[i][k] != strs[j][k]) {
                            diff++;
                        }
                    }
                    //如果相差的字符个数为0或者2，这两个元素满足条件，将其和并到一个集合里
                    if (diff == 0 || diff == 2) {
                        setUnion(i, j);
                    }
                }
            }
        }
        return sets;
    }
};
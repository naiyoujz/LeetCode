//
// Created by xili on 2024/7/25 22:25.
// Go big or go home.
//
#include <vector>

using namespace std;

class Solution {
public:
    //当前元素所在集合的代表元素
    static vector<int> father;
    //集合的数量
    static int sets;

    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        build(n / 2);
        for (int i = 0; i < n; i += 2) {
            setsUnion(row[i] / 2, row[i + 1] / 2);
        }
        return n / 2 - sets;
    }

    //构建m个集合
    void build(int m) {
        father.resize(m);
        for (int i = 0; i < m; i++) {
            father[i] = i;
        }
        sets = m;
    }

    //寻找该元素所在集合代表元素
    int find(int i) {
        if (i != father[i]) {
            father[i] = find(father[i]);
        }
        return father[i];
    }

    //将x y所在的集合合并
    static void setsUnion(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
            sets--;
        }
    }
};

vector<int>Solution::father;
int Solution::sets;

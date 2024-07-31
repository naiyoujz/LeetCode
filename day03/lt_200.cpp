//
// Created by xili on 2024/7/26 9:59.
// Go big or go home.
//

#include <vector>

using namespace std;

//并查集
class Solution1 {
public:
    vector<int> father;
    int sets;
    int row;
    int col;

    //将二维下标转化成一维
    int index(int a, int b) {
        return a * col + b;
    }

    int find(int p) {
        if (p != father[p]) {
            father[p] = find(father[p]);
        }
        return father[p];
    }

    void setUnion(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            father[fx] = fy;
            sets--;
        }
    }

    void build(vector<vector<char>> &grid) {
        row = grid.size();
        col = grid[0].size();
        sets = 0;
        father.resize(row * col, -1);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                //将‘1’标记为单独的一个集合
                if (grid[i][j] == '1') {
                    int k = index(i, j);
                    father[k] = k;
                    sets++;
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        build(grid);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                //如果当前元素是‘1’，判断前一个和前一行对应元素是否为‘1’，是则加入集合
                if (grid[i][j] == '1') {
                    if (j > 0 && grid[i][j - 1] == '1') {
                        setUnion(index(i, j), index(i, j - 1));
                    }
                    if (i > 0 && grid[i - 1][j] == '1') {
                        setUnion(index(i, j), index(i - 1, j));
                    }
                }
            }
        }
        return sets;
    }
};
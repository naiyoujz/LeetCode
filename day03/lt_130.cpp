//
// Created by xili on 2024/7/26 11:11.
// Go big or go home.
//
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[row - 1][i] == 'O') {
                dfs(board, row - 1, i);
            }
        }
        for (int i = 1; i < row - 1; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][col - 1] == 'O') {
                dfs(board, i, col - 1);
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j) {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'T';
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
    }
};
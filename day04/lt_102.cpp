//
// Created by xili on 2024/7/27 11:47.
// Go big or go home.
//
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        //根节点不存在，直接返回
        if (!root) {
            return ans;
        }
        queue<TreeNode *> q;
        //将根节点入队
        q.push(root);
        //当队列不为空
        while (!q.empty()) {
            vector<int> help;
            //记录当前队列的大小，弹出的节点数量为队列大小
            int size = q.size();
            for (int i = 0; i < size; i++) {
                //获取队头节点
                auto cur = q.front();
                //弹出队头节点
                q.pop();
                //将当前节点的值存入辅助数组中
                help.push_back(cur->val);
                //有左孩子，入队
                if (cur->left) {
                    q.push(cur->left);
                }
                //有右孩子，入队
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            //将辅助数组的加到答案中，进行下次循环
            ans.push_back(help);
        }
        return ans;
    }
};
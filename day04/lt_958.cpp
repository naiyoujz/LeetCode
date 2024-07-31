//
// Created by xili on 2024/7/27 14:03.
// Go big or go home.
//
#include <queue>

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
    bool isCompleteTree(TreeNode *root) {
        if (!root) {
            return true;
        }
        //使用队列进行层次优先遍历
        queue<TreeNode *> tq;
        tq.push(root);
        //是否遇到左右孩子不全的节点
        bool LorR = false;
        while (!tq.empty()) {
            auto cur = tq.front();
            tq.pop();
            //1.是否有节点有右无左
            //2.如果遇到了左右孩子不全的节点，剩下的孩子全是叶子节点
            if ((cur->right && !cur->left) || (LorR && (cur->left || cur->right))) {
                return false;
            }
            if (cur->left) {
                tq.push(cur->left);
            }
            if (cur->right) {
                tq.push(cur->right);
            }
            if (!cur->left || !cur->right) {
                LorR = true;
            }
        }
        return true;
    }
};
//
// Created by xili on 2024/7/27 16:46.
// Go big or go home.
//

#include <algorithm>

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
    //搜索二叉树：左子树小于根节点小于右子树
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int minV = min(p->val, q->val);
        int maxV = max(p->val, q->val);
        //1.当前节点等于p或q的任意一个
        while (root->val != minV && root->val != maxV) {
            //2.当前节点处在p q中间
            if (root->val > minV && root->val < maxV) {
                break;
            }
            //3.当前节点比最大的还大，取左子树找
            else if (root->val > maxV) {
                root = root->left;
            }
            //4当前节点比最小的还小，去右子树找
            else {
                root = root->right;
            }
        }
        //返回找到的节点
        return root;
    }
};

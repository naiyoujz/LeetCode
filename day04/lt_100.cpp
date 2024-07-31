//
// Created by xili on 2024/7/27 17:19.
// Go big or go home.
//

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        //p q都为空
        if (!p && !q) {
            return true;
        }
        //p q 有一个是空
        else if ((p && !q) || (!p && q)) {
            return false;
        }
        //p q 存在，但值不一样
        else if (p->val != q->val) {
            return false;
        }
        //递归判断左右孩子节点
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
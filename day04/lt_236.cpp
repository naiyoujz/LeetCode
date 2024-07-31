//
// Created by xili on 2024/7/27 16:32.
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        //左边没找到,右边也没找到，返回空
        if (!l && !r) {
            return nullptr;
        }
        //左边找到了，右边也找到了，返回root
        if (l && r) {
            return root;
        }
        //返回找到了的那一个
        return l ? l : r;
    }
};
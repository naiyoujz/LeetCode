//
// Created by xili on 2024/7/28 12:51.
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
    bool isBalanced(TreeNode *root) {
        //平衡二叉树每个节点左右高度差不超过1
        return root == nullptr || (abs(height(root->left) - height(root->right)) <= 1
                                   && isBalanced(root->left) && isBalanced(root->right));
    }

    int height(TreeNode *root) {
        //求树的最大高度
        return root == nullptr ? 0 : max(height(root->left), height(root->right)) + 1;
    }
};
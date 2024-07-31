//
// Created by xili on 2024/7/27 18:48.
// Go big or go home.
//
#include <vector>

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
    void inorder(TreeNode *root, vector<int> &ans) {
        if (!root) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode *increasingBST(TreeNode *root) {
        vector<int> ans;
        inorder(root, ans);
        TreeNode *dummyHead = new TreeNode(-1);
        TreeNode *head = dummyHead;
        for (auto &item: ans) {
            TreeNode *node = new TreeNode(item);
            head->right = node;
            head = node;
        }
        return dummyHead->right;
    }
};
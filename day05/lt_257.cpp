//
// Created by xili on 2024/7/28 13:07.
// Go big or go home.
//
#include <vector>
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
    vector<string> ans;

    vector<string> binaryTreePaths(TreeNode *root) {
        f(root, "");
        return ans;
    }

    void f(TreeNode *root, string path) {
        //将当前节点加入到路径中
        path += to_string(root->val);
        if (!root->left && !root->right) {
            //到叶子节点后，将路径加入到答案中
            ans.push_back(path);
            return;
        }
        //有左孩子或者右孩子，继续递归增加路径
        if (root->left) {
            f(root->left, path + "->");
        }
        if (root->right) {
            f(root->right, path + "->");
        }
    }
};
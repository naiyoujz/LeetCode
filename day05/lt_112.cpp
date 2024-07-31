//
// Created by xili on 2024/7/28 14:00.
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
    bool hasPathSum(TreeNode *root, int targetSum) {
        // 如果节点为空，返回 false
        if (!root) {
            return false;
        }
        // 如果是叶子节点且路径和等于 targetSum，返回 true
        if (!root->left && !root->right && root->val == targetSum) {
            return true;
        }
        // 递归检查左子树和右子树
        int newTargetSum = targetSum - root->val;
        return hasPathSum(root->left, newTargetSum) || hasPathSum(root->right, newTargetSum);
    }
};

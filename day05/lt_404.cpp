//
// Created by xili on 2024/7/28 13:19.
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
    int ans = 0;

    int sumOfLeftLeaves(TreeNode *root) {
        return help(root);
    }

    int help(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (root->left) {
          if(!root->left->left&&!root->left->right){
              ans+=root->left->val;
          }
            help(root->left);
        }
        if (root->right) {
            help(root->right);
        }
        return ans;
    }
};
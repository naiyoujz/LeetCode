//
// Created by xili on 2024/7/27 18:00.
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
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return check(root->left, root->right);
    }

    bool check(TreeNode *p, TreeNode *q) {
        //p q都不存在
        if (!p && !q) {
            return true;
        }
        //p q有一边不存在
        if (!p || !q) {
            return false;
        }
        //p q的值相等，且p和q都是对称的
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
};
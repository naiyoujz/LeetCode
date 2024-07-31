//
// Created by xili on 2024/7/27 15:03.
// Go big or go home.
//

#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> m;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty() || inorder.empty() || postorder.size() != inorder.size()) {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        return f(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode *f(vector<int> &post, int l1, int r1, vector<int> &in, int l2, int r2) {
        if (l1 > r1) {
            return nullptr;
        }
        TreeNode *head = new TreeNode(post[r1]);
        if (l1 == r1) {
            return head;
        }
        //在中序遍历里找到头节点的下标
        int k = m[post[r1]];
        //后序：[l1......r1]
        //中序：[l2...k...r2]
        //        r1==k
        head->left = f(post, l1, l1 + k - l2 - 1, in, l2, k - 1);
        head->right = f(post, l1 + k - l2, r1 - 1, in, k + 1, r2);
        return head;
    }
};

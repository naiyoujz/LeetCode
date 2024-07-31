//
// Created by xili on 2024/7/28 12:35.
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return help(nums, 0, nums.size() - 1);
    }

    TreeNode *help(vector<int> &nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int m = (l + r) >> 1;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = help(nums, l, m - 1);
        root->right = help(nums, m + 1, r);
        return root;
    }
};
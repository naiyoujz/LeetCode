//
// Created by xili on 2024/7/27 17:03.
// Go big or go home.
//
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> ans;

    vector<int> preorder(Node *root) {
        f(root);
        return ans;
    }

    void f(Node *root) {
        //如果节点为空，直接返回
        if (!root) {
            return;
        }
        ans.push_back(root->val);
        //递归遍历所有孩子
        for (auto &item: root->children) {
            f(item);
        }
    }
};
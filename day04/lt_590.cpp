//
// Created by xili on 2024/7/27 20:18.
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

    vector<int> postorder(Node *root) {
        post(root);
        return ans;
    }

    void post(Node *root) {
        if (!root) {
            return;
        }
        for (auto &item: root->children) {
            post(item);
        }
        ans.push_back(root->val);
    }
};
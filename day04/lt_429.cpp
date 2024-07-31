//
// Created by xili on 2024/7/27 20:29.
// Go big or go home.
//
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int cnts = q.size();
            for (int i = 0; i < cnts; i++) {
                Node *cur = q.front();
                temp.push_back(cur->val);
                q.pop();
                for (auto &item: cur->children) {
                    q.push(item);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
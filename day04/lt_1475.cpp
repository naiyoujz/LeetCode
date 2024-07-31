//
// Created by xili on 2024/7/27 20:46.
// Go big or go home.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        //单调栈 严格大压小
        stack<int> s;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && prices[i] <= prices[s.top()]) {
                prices[s.top()] -= prices[i];
                s.pop();
            }
            s.push(i);
        }
        return prices;
    }
};
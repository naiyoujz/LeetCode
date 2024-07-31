//
// Created by xili on 2024/7/25 11:26.
// Go big or go home.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        //统计长度较短的数组各个元素的数量
        if (nums1.size() > nums2.size()) {
            intersect(nums2, nums1);
        }
        unordered_map<int, int> umap;
        vector<int> ans;
        for (int &ele: nums1) {
            umap[ele]++;
        }
        //看nums2中的元素否再num1中出现，出现过则将个数减一，个数为0时删除当前元素
        for (int &ele: nums2) {
            if (umap.count(ele)) {
                ans.push_back(ele);
                umap[ele]--;
            }
            if (!umap[ele]) {
                umap.erase(ele);
            }
        }
        return ans;
    }
};
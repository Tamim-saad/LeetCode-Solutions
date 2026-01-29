/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  TreeNode *TreeWithPos(vector<int> &nums, int l, int h) {
    if(l>h) return nullptr;

    int m = (l + h) / 2;
    TreeNode *root = new TreeNode(nums[m]);

    root->left = TreeWithPos(nums, l, m - 1);
    root->right = TreeWithPos(nums, m + 1, h);
    return root;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return TreeWithPos(nums, 0, nums.size() - 1);
  }
};
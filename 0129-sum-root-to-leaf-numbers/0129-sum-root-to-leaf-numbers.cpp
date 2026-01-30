#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nums;
  void check(TreeNode *root, int curr) {
    if (!root)
      return;

    curr *= 10;
    curr += root->val;

    if (!root->left && !root->right) {
      nums.emplace_back(curr);
      return;
    }

    check(root->left, curr);
    check(root->right, curr);
  }
  int sumNumbers(TreeNode *root) {
    check(root, 0);
    return accumulate(nums.begin(), nums.end(), 0);
  }
};
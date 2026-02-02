#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int ans = INT_MIN;
  pair<int, int> recur(TreeNode *root) {
    if (!root)
      return {0, 0};

    int left = 0, right = 0;
    if (root->left) {
      left = 1 + recur(root->left).second;
    }
    if (root->right) {
      right = 1 + recur(root->right).first;
    }

    ans = max({left, ans, right});

    return {left, right};
  }

  int longestZigZag(TreeNode *root) {
    recur(root);
    return ans;
  }
};
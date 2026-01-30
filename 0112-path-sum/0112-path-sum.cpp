#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkSum(TreeNode *root, int &targetSum, int curr) {
    if (!root)
      return false;

    curr += root->val;

    if (!root->left && !root->right) {
      if (curr == targetSum)
        return true;
      return false;
    }

    return checkSum(root->left, targetSum, curr) ||
           checkSum(root->right, targetSum, curr);
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    return checkSum(root, targetSum, 0);
  }
};
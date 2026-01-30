#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;

    int left = root->left ? countNodes(root->left) : 0;
    int right = root->right ? countNodes(root->right) : 0;
    return 1 + left + right;
  }
};
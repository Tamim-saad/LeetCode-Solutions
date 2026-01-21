
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isMirror(TreeNode *l, TreeNode *r) {
    if (!l && !r)
      return true;
    if (!l || !r)
      return false;

    return l->val == r->val && isMirror(l->left, r->right) &&
           isMirror(l->right, r->left);
  }
  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    return isMirror(root->left, root->right);
  }
};
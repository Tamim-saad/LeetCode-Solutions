#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  map<TreeNode *, bool> mp, mp2;

  bool recur(TreeNode *root, TreeNode *x, map<TreeNode *, bool> &mp) {
    if (!root)
      return false;
    if (root->val == x->val)
      return mp[root] = true;

    return mp[root] = recur(root->left, x, mp) || recur(root->right, x, mp);
  }

  TreeNode *search(TreeNode *root) {
    auto x = root->val;

    if (root->left && mp[root->left] && mp2[root->left]) {
      return search(root->left);
    } else if (root->right && mp[root->right] && mp2[root->right]) {
      return search(root->right);
    } else {
      return root;
    }
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    recur(root, p, mp);
    recur(root, q, mp2);

    return search(root);
  }
};
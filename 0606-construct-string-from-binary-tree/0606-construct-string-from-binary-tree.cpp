#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void encode(TreeNode *root, string &ans) {
    if (!root)
      return;

    ans += to_string(root->val);

    if (!root->left && !root->right)
      return;

    ans += "(";
    encode(root->left, ans);
    ans += ")";

    if (root->right) {
      ans += "(";
      encode(root->right, ans);
      ans += ")";
    }
  }

  string tree2str(TreeNode *root) {
    string ans = "";
    encode(root, ans);
    return ans;
  }
};

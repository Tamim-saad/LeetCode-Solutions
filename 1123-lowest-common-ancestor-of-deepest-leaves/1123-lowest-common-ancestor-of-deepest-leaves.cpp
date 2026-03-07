
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  TreeNode *ans = nullptr;
  int maxLevel(TreeNode *root) {
    if (!root)
      return 0;

    return max(maxLevel(root->left), maxLevel(root->right)) + 1;
  }

  int recur(TreeNode *root, int currlevel, int &maxLev) {
    if (!root)
      return currlevel;

    currlevel++;

    int l = recur(root->left, currlevel, maxLev);
    int r = recur(root->right, currlevel, maxLev);

    if ((l == maxLev && r == maxLev) ||
        (l == 0 && r == 0 && currlevel == maxLev))
      ans = root;

    return max(l, r);
  }

  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    int maxLev = maxLevel(root);

    cout << maxLev << endl;
    recur(root, 0, maxLev);
    return ans;
  }
};

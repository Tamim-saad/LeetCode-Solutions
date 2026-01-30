#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    if (!root)
      return 0;

    int ans = INT_MIN, ind, level = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      int sum = 0;
      level++;

      for (int i = 0; i < size; i++) {
        auto x = q.front();
        q.pop();

        sum += x->val;

        if (x->left)
          q.push(x->left);
        if (x->right)
          q.push(x->right);
      }

      if (sum > ans) {
        ind = level;
        ans = sum;
      }
    }

    return ind;
  }
};
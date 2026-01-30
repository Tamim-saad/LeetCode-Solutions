#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    if (!root) {
      ans.emplace_back(0);
      return ans;
    }

    queue<TreeNode *> q;
    q.push(root);
    double sum = 0, cnt = 0;

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        auto x = q.front();
        q.pop();

        sum += x->val;
        cnt++;

        if (x->left)
          q.push(x->left);
        if (x->right)
          q.push(x->right);
      }

      ans.emplace_back(sum / cnt);
      sum = 0;
      cnt = 0;
    }

    return ans;
  }
};
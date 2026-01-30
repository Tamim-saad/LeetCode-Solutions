#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root)
      return ans;

    queue<TreeNode *> q;
    q.push(root);
    deque<int> dq;
    bool leftToRight = false;

    while (!q.empty()) {
      int size = q.size();
      leftToRight = !leftToRight;

      for (int i = 0; i < size; i++) {
        auto x = q.front();
        q.pop();

        if (leftToRight)
          dq.push_back(x->val);
        else
          dq.push_front(x->val);

        if (x->left)
          q.push(x->left);
        if (x->right)
          q.push(x->right);
      }

      ans.emplace_back(vector<int>(dq.begin(), dq.end()));
      dq.clear();
    }

    return ans;
  }
};
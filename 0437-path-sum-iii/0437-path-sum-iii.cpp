#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int ans = 0;
  unordered_map<long long, int> mp;
  void dfs(TreeNode *root, long long sum, int &target) {
    if (!root)
      return;

    sum += root->val;
    ans += mp[sum - target];
    mp[sum]++;

    dfs(root->left, sum, target);
    dfs(root->right, sum, target);

    mp[sum]--;
  }
  int pathSum(TreeNode *root, int targetSum) {
    mp[0] = 1;
    dfs(root, 0, targetSum);
    return ans;
  }
};
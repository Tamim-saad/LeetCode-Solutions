#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int ans = 0;
  
  // Note: I removed the 'sum' parameter from your signature because 
  // we will calculate it dynamically to handle negative numbers.
  void dfs(TreeNode *root, deque<int> path, int target) {
    if (!root)
      return;

    // 1. Add current node to your path
    path.emplace_back(root->val);

    // 2. Check all paths ending at the current node
    // We use 'long long' here because LeetCode has test cases with massive 
    // integers that will overflow a standard 32-bit int.
    long long current_sum = 0; 
    for (int i = path.size() - 1; i >= 0; i--) {
      current_sum += path[i];
      if (current_sum == target) {
        ans++;
      }
    }

    // 3. Continue DFS. 
    // Passing 'path' by value (as you did) implicitly handles backtracking!
    dfs(root->left, path, target);
    dfs(root->right, path, target);
  }
  
  int pathSum(TreeNode *root, int targetSum) {
    // Start the DFS with an empty deque
    dfs(root, {}, targetSum);
    return ans;
  }
};
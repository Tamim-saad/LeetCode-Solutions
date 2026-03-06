#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
  int maxi = 0;
  map<int, int> mp;

  int searchMax(TreeNode *root, int level) {
    if (!root) return 0;
    level += 1;
    mp[root->val] = level;
    maxi = max(level, maxi);
    searchMax(root->left, level);
    searchMax(root->right, level);
    return mp[root->val];
  }

  TreeNode *lowestRoot = nullptr;

  // minimal change: traverse now returns the maximum depth found in this subtree
  int traverse(TreeNode *root) {
    if (!root) return 0;

    int leftMax = traverse(root->left);
    int rightMax = traverse(root->right);

    int curr = mp[root->val];
    int subtreeMax = max(curr, max(leftMax, rightMax));

    // if both child-subtrees contain deepest-level nodes, this node is LCA
    if (leftMax == maxi && rightMax == maxi) {
      lowestRoot = root;
    }

    // single deepest leaf case
    if (!root->left && !root->right && curr == maxi) {
      lowestRoot = root;
    }

    return subtreeMax;
  }

  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    searchMax(root, 0);
    traverse(root);
    return lowestRoot;
  }
};
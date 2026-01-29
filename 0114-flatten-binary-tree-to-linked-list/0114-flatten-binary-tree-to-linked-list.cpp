#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  TreeNode *flattenWithRoot(TreeNode *root) {
    if (!root)
      return nullptr;

    TreeNode *rightSaved = nullptr;

    if (root->right) {
      rightSaved = root->right;
    }

    if (root->left) {
      root->right = flattenWithRoot(root->left);

      TreeNode *rightLast = root;
      while (rightLast->right) {
        root->left = nullptr;
        rightLast = rightLast->right;
      }
      rightLast->right = flattenWithRoot(rightSaved);
    } else {
      root->right = flattenWithRoot(root->right);
    }

    return root;
  }

  void flatten(TreeNode *root) { flattenWithRoot(root); }
};
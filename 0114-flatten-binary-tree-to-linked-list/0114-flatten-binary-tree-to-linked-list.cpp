#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  TreeNode *flattenWithRoot(TreeNode *root) {
    if (!root)
      return nullptr;

    TreeNode *rightSaved = root->right ? root->right : nullptr;
    TreeNode *rightLast = root;

    if (root->left) {
      root->right = flattenWithRoot(root->left);

      while (rightLast->right) {
        root->left = nullptr;
        rightLast = rightLast->right;
      }
    }
    rightLast->right = flattenWithRoot(rightSaved);

    return root;
  }

  void flatten(TreeNode *root) { flattenWithRoot(root); }
};
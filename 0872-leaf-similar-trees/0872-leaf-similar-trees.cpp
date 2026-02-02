#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void getLeaf(TreeNode *root, vector<int> &seq) {
    if (!root->left && !root->right) {
      seq.emplace_back(root->val);
    }
    if (root->left)
      getLeaf(root->left, seq);

    if (root->right)
      getLeaf(root->right, seq);
  }
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> seq1, seq2;
    getLeaf(root1, seq1);
    getLeaf(root2, seq2);

    return seq1 == seq2;
  }
};
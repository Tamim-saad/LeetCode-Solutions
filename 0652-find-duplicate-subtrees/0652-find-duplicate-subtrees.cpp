#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    unordered_map<string, int> subtree_counts;
    vector<TreeNode *> duplicates;

    serialize_tree(root, subtree_counts, duplicates);
    return duplicates;
  }

private:
  string serialize_tree(TreeNode *root, unordered_map<string, int> &counts,
                        vector<TreeNode *> &duplicates) {
    if (!root)
      return "#";

    string leftString = serialize_tree(root->left, counts, duplicates);
    string rightString = serialize_tree(root->right, counts, duplicates);
    string curr = leftString + "," + rightString + "," + to_string(root->val);

    counts[curr]++;
    if (counts[curr] == 2)
      duplicates.push_back(root);

    return curr;
  }
};
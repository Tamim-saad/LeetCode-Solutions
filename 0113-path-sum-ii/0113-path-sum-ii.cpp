class Solution {
public:
  vector<vector<int>> ans;
  void dfs(TreeNode *root, vector<int> &curr, int &sum, int target) {
    if (!root)
      return;

    curr.emplace_back(root->val);
    sum += root->val;

    if (!root->left && !root->right && sum == target) {
      ans.emplace_back(curr);
    }

    dfs(root->left, curr, sum, target);
    dfs(root->right, curr, sum, target);
    curr.pop_back();
    sum -= root->val;
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<int> tmp;
    int sum = 0;
    dfs(root, tmp, sum, targetSum);
    return ans;
  }
};

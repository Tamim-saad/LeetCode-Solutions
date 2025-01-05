// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void backtrack(vector<int> &nums, vector<int> curr, int ind,
                 vector<vector<int>> &ans) {
    if (ind >= nums.size()) {
      ans.emplace_back(curr);
      return;
    }

    backtrack(nums, curr, ind + 1, ans);
    curr.emplace_back(nums[ind]);
    backtrack(nums, curr, ind + 1, ans);
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    backtrack(nums, {}, 0, ans);
    return ans;
  }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void recur(set<vector<int>> &ans, vector<int> curr, int k, int &n, int sum,
             int dgit) {
    if (sum == n && curr.size() == k) {
      ans.insert(curr);
      return;
    }

    if (sum > n || dgit > 9 || curr.size() > k)
      return;

    recur(ans, curr, k, n, sum, dgit + 1);
    curr.emplace_back(dgit);
    recur(ans, curr, k, n, sum + dgit, dgit + 1);
    curr.pop_back();
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    set<vector<int>> st;
    recur(st, {}, k, n, 0, 1);

    vector<vector<int>> ans;
    for (auto x : st)
      ans.emplace_back(vector<int>(x.begin(), x.end()));
    return ans;
  }
};
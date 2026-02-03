#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> visited;
  int cnt = 0;
  void dfs(vector<vector<int>> &uni, vector<vector<int>> &bi, int curr) {
    visited[curr] = true;

    for (auto x : bi[curr]) {
      if (!visited[x]) {
        if (binary_search(uni[curr].begin(), uni[curr].end(), x))
          cnt++;
        dfs(uni, bi, x);
      }
    }
  }

  int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<int>> bi(n), uni(n);
    visited.resize(n + 1, false);

    for (auto x : connections) {
      bi[x[0]].emplace_back(x[1]);
      bi[x[1]].emplace_back(x[0]);
      uni[x[0]].emplace_back(x[1]);
    }

    for (auto &x : uni)
      sort(x.begin(), x.end());

    dfs(uni, bi, 0);
    return cnt;
  }
};
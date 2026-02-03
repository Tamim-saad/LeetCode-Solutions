#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> visited;
  int cnt = 0;
  void dfs(vector<vector<int>> &graph, int curr) {
    if (visited[curr])
      return;
    visited[curr] = true;
    for (auto x : graph[curr]) {
      dfs(graph, x);
    }
  }

  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    vector<vector<int>> neighbours(n);
    visited.resize(n + 1, false);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j]) {
          neighbours[i].emplace_back(j);
          neighbours[j].emplace_back(i);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        cnt++;
        dfs(neighbours, i);
      }
    }

    dfs(neighbours, 0);
    return cnt;
  }
};
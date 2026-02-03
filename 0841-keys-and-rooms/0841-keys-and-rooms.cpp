#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> visited;
  int cnt = 0;
  void dfs(vector<vector<int>> &rooms, int curr, int &n) {
    if (visited[curr])
      return;
    visited[curr] = true;
    cnt++;
    for (auto x : rooms[curr]) {
      dfs(rooms, x, n);
    }
  }

  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    visited.resize(n + 1, false);

    dfs(rooms, 0, n);
    return cnt == rooms.size();
  }
};
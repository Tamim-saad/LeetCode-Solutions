#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int ans = 0;
  vector<pair<int, int>> neighbour = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<int>> dp;

  int dfs(vector<vector<int>> &board, int r, int c, int prev) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
      return 0;

    auto curr = board[r][c];
    if (curr <= prev)
      return 0;

    if (dp[r][c] != -1)
      return dp[r][c];

    int maxi = 0;
    for (auto &[x, y] : neighbour)
      maxi = max(maxi, dfs(board, r + x, c + y, curr));

    return dp[r][c] = 1 + maxi;
  }

  int longestIncreasingPath(vector<vector<int>> &matrix) {
    dp.resize(201, vector<int>(201, -1));

    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        dp[r][c] = dfs(matrix, r, c, INT_MIN);
        ans = max(ans, dp[r][c]);
      }
    }

    return ans;
  }
};

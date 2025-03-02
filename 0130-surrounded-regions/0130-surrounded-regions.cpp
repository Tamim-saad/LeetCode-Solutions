// say Alhamdulillah

#include <bits/stdc++.h>
#include <vector>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     indexed_multiset;

#define ll unsigned long long

class Solution {
 public:
  // map<pair<int, int>, pair<int, int>> mp;
  // map<pair<int, int>, int> vis;

  void dfs(vector<vector<char>> &board, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 'X' || board[i][j] == '1') return;
    board[i][j] = '1';

    dfs(board, i - 1, j, m, n);
    dfs(board, i, j - 1, m, n);
    dfs(board, i + 1, j, m, n);
    dfs(board, i, j + 1, m, n);
  }

  void solve(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O') {
          dfs(board, i, j, m, n);
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] != '1') {
          board[i][j] = 'X';
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '1') {
          board[i][j] = 'O';
        }
      }
    }
  }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<pair<int, int>> neighbours = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                       {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  bool getNeigh(vector<vector<int>> &board, int &i, int &j, int &r, int &c) {
    if (i < 0 || i >= r || j < 0 || j >= c)
      return 0;
    return board[i][j] == 1 || board[i][j] == 3;
  }

  void gameOfLife(vector<vector<int>> &board) {
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int cnt = 0;

        for (auto &[x, y] : neighbours) {
          int nx = i + x;
          int ny = j + y;
          cnt += getNeigh(board, nx, ny, r, c);
        }

        if (board[i][j] == 1 && (cnt == 2 || cnt == 3))
          board[i][j] = 1;
        else if ((board[i][j] == 0 && cnt == 3))
          board[i][j] = 2;
        else if (board[i][j] == 1 && (cnt < 2 || cnt > 3))
          board[i][j] = 3;
        else
          board[i][j] = -1;
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (board[i][j] == -1 || board[i][j] == 3)
          board[i][j] = 0;
        if (board[i][j] == 2)
          board[i][j] = 1;
      }
    }
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    int m = maze.size();
    int n = maze[0].size();

    queue<tuple<int, int, int>> q;
    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    q.push({entrance[0], entrance[1], 0});
    maze[entrance[0]][entrance[1]] = '+';

    while (!q.empty()) {
      auto [x, y, w] = q.front();
      q.pop();

      if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) &&
          !(x == entrance[0] && y == entrance[1]))
        return w;

      for (auto [dx, dy] : neighbours) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny] == '+')
          continue;

        q.push(make_tuple(nx, ny, w + 1));
        maze[nx][ny] = '+';
      }
    }
    return -1;
  }
};
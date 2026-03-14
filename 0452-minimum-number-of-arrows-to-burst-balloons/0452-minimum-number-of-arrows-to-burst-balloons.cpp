#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(),
         [](vector<int> &x, vector<int> &y) { return x[1] < y[1]; });

    int n = points.size();

    int cnt = 0;
    for (int i = 0; i < n;) {
      int j = i;

      while (j < n && points[i][1] >= points[j][0])
        j++;
      cnt++;
      i = j;
    }

    return cnt;
  }
};
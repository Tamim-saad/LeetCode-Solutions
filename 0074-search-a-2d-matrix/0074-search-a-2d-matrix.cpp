// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    vector<int> v;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        v.emplace_back(matrix[i][j]);
      }
    }
    int ind = lower_bound(v.begin(), v.end(), target) - v.begin();
    if (ind < v.size() && v[ind] == target)
      return true;
    return false;
  }
};
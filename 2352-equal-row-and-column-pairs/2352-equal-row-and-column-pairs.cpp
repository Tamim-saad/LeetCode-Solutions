
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    map<vector<int>, int> mp, mp2;
    for (int i = 0; i < grid.size(); i++) {
      mp[grid[i]]++;
    }
    vector<vector<int>> vertical(grid[0].size());
    for (int i = 0; i < grid[0].size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        vertical[i].emplace_back(grid[j][i]);
      }
    }

    for (int i = 0; i < vertical.size(); i++) {
      mp2[vertical[i]]++;
    }

    int ans = 0;

    for (auto x : mp) {
      if (mp2.find(x.first) != mp2.end()) {
        ans += mp[x.first] * mp2[x.first];
      }
    }
    return ans;
  }
};
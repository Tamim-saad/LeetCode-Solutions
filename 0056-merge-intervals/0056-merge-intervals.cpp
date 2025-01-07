// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> vans;

    for (int i = 0; i < intervals.size(); i++) {
      if (!i || vans.back()[1] < intervals[i][0])
        vans.emplace_back(intervals[i]);
      else
        vans.back()[1] = max(vans.back()[1], intervals[i][1]);
    }

    return vans;
  }
};

// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> vans;
    vans.push_back(intervals[0]);

    int i = 1;
    while (i < intervals.size()) {
      if (vans[vans.size() - 1][1] >= intervals[i][0])
        vans[vans.size() - 1][1] =
            max(vans[vans.size() - 1][1], intervals[i][1]);
      else
        vans.push_back({intervals[i][0], intervals[i][1]});
      i++;
    }

    return vans;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int n = intervals.size();
    if (n == 0)
      return {newInterval};

    int i = 0;
    while (i < intervals.size() && newInterval[0] > intervals[i][1])
      i++;

    if (i == n || newInterval[1] < intervals[i][0]) {
      intervals.insert(intervals.begin() + i, newInterval);
      return intervals;
    }

    int eraseStart = i;
    int mini = min(intervals[i][0], newInterval[0]);
    int maxi = max(intervals[i][1], newInterval[1]);

    while (i < n && maxi >= intervals[i][0]) {
      maxi = max(intervals[i][1], maxi);
      i++;
    }

    int eraseEnd = i;

    vector<vector<int>> ans;
    for (int i = 0; i < eraseStart; i++)
      ans.emplace_back(intervals[i]);

    ans.push_back({mini, maxi});
    for (int i = eraseEnd; i < intervals.size(); i++)
      ans.emplace_back(intervals[i]);

    return ans;
  }
};
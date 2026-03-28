#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
      dp[i] = min(dp[i], cost[i] + min(dp[i - 1], dp[i - 2]));

    return min(dp[n - 2], dp[n - 1]);
  }
};
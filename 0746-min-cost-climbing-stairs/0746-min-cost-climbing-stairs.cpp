#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    vector<int> dp(n, INT_MAX);
    // dp[0] = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 1; j < 3; j++) {
        int prev = j > i ? 0 : dp[i - j];
        dp[i] = min(dp[i], prev + cost[i]);
      }
    }
    return min(dp[n - 2], dp[n - 1]);
  }
};
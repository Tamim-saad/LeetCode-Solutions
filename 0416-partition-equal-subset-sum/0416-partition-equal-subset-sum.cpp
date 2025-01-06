// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    bitset<20001> dp;
    dp[0] = 1;
    int sum = 0;

    for (auto x : nums) {
      dp |= (dp << x);
      sum += x;
    }
    if (sum % 2)
      return false;
    if (dp[sum / 2])
      return true;
    return false;
  }
};
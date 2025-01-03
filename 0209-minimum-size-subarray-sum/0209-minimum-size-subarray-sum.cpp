// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int i, j, sum;
    i = j = sum = 0;
    int ans = INT_MAX;

    while (i < nums.size()) {
      sum += nums[i];

      while (sum >= target) {
        ans = min(ans, i - j + 1);
        sum -= nums[j++];
      }
      i++;
    }
    return ans == INT_MAX ? 0 : ans;
  }
};

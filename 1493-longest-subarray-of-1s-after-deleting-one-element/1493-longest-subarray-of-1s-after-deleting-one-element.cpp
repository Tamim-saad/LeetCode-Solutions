#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int sum = 0;
    vector<int> v;

    for (auto x : nums) {
      if (sum && !x)
        v.emplace_back(sum);
      if (x == 0)
        v.emplace_back(0);

      sum += x;
      sum *= x;
    }
    if (sum == nums.size())
      sum--;
    v.emplace_back(sum);

    int maxi = 0;
    for (int i = 0; i < v.size(); i++) {
      maxi = max(maxi, v[i]);

      if (v[i] == 0) {
        int x = i == 0 ? 0 : v[i - 1];
        int y = i == v.size() - 1 ? 0 : v[i + 1];

        maxi = max(maxi, x + y);
      }
    }

    return maxi;
  }
};
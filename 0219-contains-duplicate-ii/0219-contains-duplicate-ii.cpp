// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {

    map<int, vector<int>> mp;

    for (int i = 0; i < nums.size(); i++) {
      mp[nums[i]].emplace_back(i);
    }

    vector<int> dup = nums;

    sort(nums.begin(), nums.end());
    unique(nums.begin(), nums.end());

    bool f = false;
    for (auto &x : nums) {
      vector<int> v = mp[x];
      for (int i = 1; i < v.size(); i++) {
        if (v[i] - v[i - 1] <= k && dup[v[i]] == dup[v[i - 1]]) {
          f = true;
          break;
        }
      }
      if (f)
        break;
    }
    return f;
  }
};
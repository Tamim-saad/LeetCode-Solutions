#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    map<int, pair<int, int>> mp;

    for (auto x : nums1)
      mp[x].first = 1;
    for (auto x : nums2)
      mp[x].second = 1;

    vector<int> ans;
    for (auto x : mp) {
      if (x.second.first == 1 && x.second.second == 1)
        ans.emplace_back(x.first);
    }

    return ans;
  }
};
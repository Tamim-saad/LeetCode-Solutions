#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              ll success) {
    sort(potions.begin(), potions.end());
    int n = potions.size();
    ll curr;

    vector<int> ans;
    for (auto x : spells) {
      int l = 0, h = n - 1;

      while (l < h) {
        int m = (l + h) / 2;

        curr = (ll)x * (ll)potions[m];
        if (curr < success)
          l = m + 1;
        else
          h = m;
      }

      curr = (ll)x * (ll)potions[l];
      if (l == n - 1 && curr < success)
        l++;
      ans.emplace_back(n - l);
    }
    return ans;
  }
};
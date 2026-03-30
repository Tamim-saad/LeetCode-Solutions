#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    sort(potions.begin(), potions.end());
    int n = potions.size();
    long long curr;

    vector<int> ans;
    for (auto x : spells) {
      int l = 0, h = n - 1;

      while (l < h) {
        int m = (l + h) / 2;

        curr = (long long)x * (long long)potions[m];
        if (curr < success)
          l = m + 1;
        else
          h = m;
      }

      curr = (long long)x * (long long)potions[l];
      if (l == n - 1 && curr < success)
        l++;
      ans.emplace_back(n - l);
    }
    return ans;
  }
};
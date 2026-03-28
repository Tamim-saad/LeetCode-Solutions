#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int mod = 1e9 + 7;
  unordered_map<int, int> mp;

  int numTilings(int n) {
    if (n < 0)
      return 0;
    if (n == 0)
      return 1;
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;
    if (n == 3)
      return 5;

    if (mp.count(n))
      return mp[n];

    return mp[n] = ((2 * numTilings(n - 1)) % mod + numTilings(n - 3)) % mod;
  }
};
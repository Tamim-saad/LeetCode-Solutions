#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int piv = 5, ans = 0;
    while (n >= piv) {
      ans += n / piv;
      piv *= 5;
    }
    return ans;
  }
};
// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double myPow(long double x, long long n) {
    if (n < 0) {
      x = 1 / x;
      n *= -1;
    }

    double ans = 1.0;
    while (n) {
      if (n & 1)
        ans *= x;
      x *= x;
      n >>= 1;
    }

    return (double)ans;
  }
};
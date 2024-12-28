// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double myPow(long double x, long long n) {
    // if (n == 0)
    //   return 1;
    // if (x == 0)
    //   return 0;

    double ans = 1.0;
    if (n < 0) {
      x = 1 / x;
      n *= -1;
    }

    while (n) {
      if (n & 1)
        ans *= x;
      x *= x;
      n >>= 1;
    }

    return (double)ans;
  }
};
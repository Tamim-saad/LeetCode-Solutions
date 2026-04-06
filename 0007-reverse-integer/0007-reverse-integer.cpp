#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    int neg = x < 0 ? 1 : 0;
    long ans = 0;
    while (x) {
      ans *= 10;
      ans += x % 10;
      x /= 10;
    }

    if (ans > INT_MAX || ans < INT_MIN)
      return 0;
    if (neg)
      ans *= -1;

    // cout << INT_M << " " << ans << endl;

    return (int)ans * (neg ? -1 : 1);
  }
};
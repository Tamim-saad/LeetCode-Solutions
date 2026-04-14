#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    long long ans = 0;
    bool neg = false, start = false;

    for (auto x : s) {
      if (!start && x == ' ')
        continue;

      if (!start && x == '-') {
        start = neg = true;
        continue;
      }
      if (!start && x == '+') {
        start = true;
        continue;
      }

      if ((x - '0') < 0 || (x - '0') > 9)
        break;

      int digit = x - '0';

      if (!neg && ans > (INT_MAX - digit) / 10)
        return INT_MAX;
      if (neg && ans > (-(long long)INT_MIN - digit) / 10)
        return INT_MIN;

      start = true;
      ans *= 10;
      ans += digit;
    }

    if (neg)
      ans *= -1;

    return (int)ans;
  }
};
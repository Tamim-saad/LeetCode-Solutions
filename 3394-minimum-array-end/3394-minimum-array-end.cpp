// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minEnd(int in, int x) {
    long long i_i = 1, i_m = 1, ans = x;
    in--;

    while (i_i <= in) {
      while (x & i_m)
        i_m <<= 1;

      ans |= ((in & i_i) ? i_m : 0);
      i_m <<= 1;
      i_i <<= 1;
    }

    return ans;
  }
};
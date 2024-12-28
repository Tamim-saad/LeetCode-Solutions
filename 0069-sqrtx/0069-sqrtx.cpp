// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    long long i = 0, n = x;
    while (i * i <= n) {
      i++;
    }
    return (int)(i - 1);
  }
};

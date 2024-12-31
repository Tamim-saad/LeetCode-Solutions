
// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int n5 = 0, n10 = 0;
    int ex5 = 0, ex10 = 0, ex20 = 0;

    // 5 5 5 10 20
    for (auto x : bills) {
      if (x == 5) {
        ex5++; // 8
      }
      if (x == 10) {
        ex5--; // 0
        ex10++;
        if (ex5 < 0)
          return false;
      }
      if (x == 20) {
        if ((ex10 >= 1 && ex5 >= 1)) {
          ex10--;
          ex5--;
        } else if (ex5 >= 3) {
          ex5 -= 3;
        } else
          return false;
      }
    }
    return true;
  }
};
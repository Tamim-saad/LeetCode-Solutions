// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int n5 = 0, n10 = 0;

    for (auto x : bills) {
      if (x == 5)
        n5++;

      if (x == 10) {
        n5--;
        n10++;
        if (n5 < 0)
          return false;
      }
      if (x == 20) {
        if ((n10 >= 1 && n5 >= 1)) {
          n10--;
          n5--;
        } else if (n5 >= 3) {
          n5 -= 3;
        } else
          return false;
      }
    }
    return true;
  }
};
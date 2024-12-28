// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    string s, t;
    while (x) {
      int r = x % 10;
      s += '0' + r;
      x /= 10;
    }
    t = s;
    reverse(t.begin(), t.end());
    if (s == t)
      return true;
    return false;
  }
};
// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    vector<int> s, t;
    while (x) {
      s.emplace_back(x % 10);
      x /= 10;
    }
    t = s;
    reverse(t.begin(), t.end());
    if (s == t)
      return true;
    return false;
  }
};
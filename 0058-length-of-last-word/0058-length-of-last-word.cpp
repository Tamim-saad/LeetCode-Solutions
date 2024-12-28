#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int ans = 0, i = s.size() - 1;

    while (s[i] == 32)
      i--;

    while (i >= 0 && s[i--] != 32)
      ans++;

    return ans;
  }
};
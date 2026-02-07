#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxVowels(string s, int k) {
    int cnt = 0;
    for (int i = 0; i < k; i++) {
      cnt += (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
              s[i] == 'u');
    }
    int ans = cnt;

    for (int i = k; i < s.size(); i++) {
      cnt -= (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' ||
              s[i - k] == 'o' || s[i - k] == 'u');
      cnt += (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
              s[i] == 'u');
      ;
      ans = max(ans, cnt);
    }

    return ans;
  }
};
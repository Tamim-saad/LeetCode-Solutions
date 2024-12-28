// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string ans = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() < b.size()) {
      int lp = b.size() - a.size();
      while (lp--)
        a += '0';
    }
    if (b.size() < a.size()) {
      int lp = a.size() - b.size();
      while (lp--)
        b += '0';
    }

    int x, y, r, c;
    char carry = '0';

    for (int i = 0; i < a.size(); i++) {
      x = (a[i] - '0');
      y = (b[i] - '0');
      c = (carry - '0');

      r = (x ^ y ^ c);
      c = ((x * y) | (y * c) | (c * x));

      carry = '0' + c;
      ans += '0' + r;
    }
    if (c)
      ans += carry;
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
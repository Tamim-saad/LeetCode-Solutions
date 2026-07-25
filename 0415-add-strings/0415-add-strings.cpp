#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();

    for (int i = 0; i < abs(n2 - n1); i++)
      if (num1.size() < num2.size())
        num1 = '0' + num1;
      else
        num2 = '0' + num2;

    int n = max(n1, n2);
    int carry = 0;
    string ans = "";

    for (int k = n - 1; k >= 0; k--) {
      int i = num1[k] - '0';
      int j = num2[k] - '0';

      int sumDigit = (i + j + carry) % 10;
      carry = (i + j + carry) / 10;

      ans += sumDigit + '0';
    }
    if (carry)
      ans += carry + '0';

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
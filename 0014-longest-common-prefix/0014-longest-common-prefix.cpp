// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string ans;
    char ch;
    for (int i = 0; i < strs[0].size(); i++) {
      ch = strs[0][i];
      for (int j = 1; j < strs.size(); j++) {
        if (!(i < strs[j].size() && ch == strs[j][i]))
          return ans;
      }
      ans += ch;
    }
    return ans;
  }
};
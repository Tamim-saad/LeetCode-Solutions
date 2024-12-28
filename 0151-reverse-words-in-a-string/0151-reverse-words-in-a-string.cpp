// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {

    int i, j;
    vector<string> v;

    for (i = 0; i < s.size(); i++) {
      while (s[i] == 32)
        i++;

      string t = "";

      while (i < s.size() && s[i] != 32) {
        t += s[i];
        i++;
      }
      t += ' ';
      v.emplace_back(t);
    }
    reverse(v.begin(), v.end());
    string rs;

    for (i = 0; i < v.size(); i++)
      for (j = 0; j < v[i].size(); j++)
        rs += v[i][j];

    while (!rs.empty() && rs[0] == 32)
      rs.erase(rs.begin());

    rs.erase(rs.size() - 1);
    return rs;
  }
};

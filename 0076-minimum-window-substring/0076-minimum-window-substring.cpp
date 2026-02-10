#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    string ans = "";
    map<char, int> pattern, mp;
    int n = t.size(), cnt = 0;

    for (auto x : t)
      pattern[x]++;

    int i = 0, j = 0;
    while (i < s.size()) {
      // if (pattern.count(s[i]) == 0) {
      //   i++;
      //   continue;
      // }

      if (mp[s[i]] < pattern[s[i]])
        cnt++;
      mp[s[i]]++;

      while (j <= i && mp[s[j]] > pattern[s[j]]) {
        mp[s[j]]--;
        j++;
      }

      // while (j <= i) {
      //   // if (!pattern.count(s[j])) {
      //   //   j++;
      //   // } else
      //   if (mp[s[j]] > pattern[s[j]]) {
      //     mp[s[j]]--;
      //   } else {
      //     break;
      //   }
      //   j++;
      // }

      if (cnt == n && (ans.empty() || i - j + 1 < ans.length()))
        ans = s.substr(j, i - j + 1);

      i++;
    }

    return ans;
  }
};
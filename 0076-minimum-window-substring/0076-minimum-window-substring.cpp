
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    string ans = "";
    map<char, int> pattern, mp;
    int target = 0, cnt = 0;
    for (auto x : t) {
      pattern[x]++;
      target++;
    }

    int i = 0, j = 0;
    while (i < s.size()) {
      auto c = s[i];
      if (!pattern.count(c)) {
        i++;
        continue;
      }

      mp[c]++;
      if (mp[c] <= pattern[c])
        cnt++;

      while (j <= i) {
        if (!pattern.count(s[j])) {
          j++;
        } else if (mp[s[j]] > pattern[s[j]]) {
          mp[s[j]]--;
          j++;
        } else {
          break;
        }
      }

      if (cnt == target && (ans.empty() || i - j + 1 < ans.length()))
        ans = s.substr(j, i - j + 1);

      i++;
    }

    return ans;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> pat(26, 0);
    for (auto x : p)
      pat[x - 'a']++;

    vector<int> curr(26, 0), ans;
    int j = 0;

    for (int i = 0; i < s.size(); i++) {
      curr[s[i] - 'a']++;

      if (i - j + 1 > p.size()) {
        curr[s[j] - 'a']--;
        j++;
      }

      if (curr == pat) {
        ans.emplace_back(j);
      }
    }
    return ans;
  }
};
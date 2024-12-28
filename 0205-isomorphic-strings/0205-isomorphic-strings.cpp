// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    map<char, char> mps, mpt;

    // vector<char> mps(256, 'a'), mpt(256, 'a');

    for (int i = 0; i < s.size(); i++) {
      if (mps[s[i]] == 0)
        mps[s[i]] = t[i];
      // if (mps.find(s[i]) == mps.end()) {
      //   mps.insert({s[i], t[i]});
      // }

      if (mps[s[i]] != t[i])
        return false;
    }
    for (int i = 0; i < t.size(); i++) {
      if (mpt[t[i]] == 0)
        mpt[t[i]] = s[i];
      // if (mpt.find(t[i]) == mpt.end()) {
      //   mpt.insert({t[i], s[i]});
      // }

      if (mpt[t[i]] != s[i])
        return false;
    }

    return true;
  }
};
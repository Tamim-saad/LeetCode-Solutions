// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    map<char, char> mps, mpt;

    for (int i = 0; i < s.size(); i++) {
      if (mps.find(s[i]) == mps.end()) {
        mps.insert({s[i], t[i]});
      }

      if (mps[s[i]] != t[i])
        return false;
    }
    for (int i = 0; i < t.size(); i++) {
      if (mpt.find(t[i]) == mpt.end()) {
        mpt.insert({t[i], s[i]});
      }

      if (mpt[t[i]] != s[i])
        return false;
    }

    return true;
  }
};
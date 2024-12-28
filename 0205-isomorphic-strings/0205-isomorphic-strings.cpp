#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {

    vector<char> mps(256, 0), mpt(256, 0);

    for (int i = 0; i < s.size(); i++) {
      if (mps[s[i]] == 0)
        mps[s[i]] = t[i];

      if (mps[s[i]] != t[i])
        return false;
    }
    for (int i = 0; i < t.size(); i++) {
      if (mpt[t[i]] == 0)
        mpt[t[i]] = s[i];

      if (mpt[t[i]] != s[i])
        return false;
    }

    return true;
  }
};
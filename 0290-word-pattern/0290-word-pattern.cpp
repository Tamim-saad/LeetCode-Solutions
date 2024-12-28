// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {

    stringstream ss(s);
    string token;
    vector<string> tokens;

    while (getline(ss, token, ' ')) {
      tokens.emplace_back(token);
    }

    if (pattern.length() != tokens.size())
      return false;
    map<char, string> mpp;
    map<string, char> mps;

    //    vector<char> mpp(256, 0), mps(256, 0);

    for (int i = 0; i < pattern.size(); i++) {
      if (mpp[pattern[i]] == "")
        mpp[pattern[i]] = tokens[i];

      if (mpp[pattern[i]] != tokens[i])
        return false;
    }
    for (int i = 0; i < tokens.size(); i++) {
      if (mps[tokens[i]] == 0)
        mps[tokens[i]] = pattern[i];

      if (mps[tokens[i]] != pattern[i])
        return false;
    }

    return true;
  }
};
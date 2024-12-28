// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    map<char, int> mp1, mp2;
    for (auto x : ransomNote)
      mp1[x]++;

    for (auto x : magazine)
      mp2[x]++;

    for (int i = 0; i <= 26; i++) {
      char c = 'a' + i;
      if (mp2[c] < mp1[c])
        return false;
      c = 'A' + i;
      if (mp2[c] < mp1[c])
        return false;
    }
    return true;
  }
};

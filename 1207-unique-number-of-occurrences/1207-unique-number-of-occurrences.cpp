
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    map<int, int> mp;
    map<int, bool> times;
    for (auto x : arr) {
      mp[x]++;
    }
    for (auto x : mp) {
      if (times.find(x.second) != times.end()) {
        return false;
      }
      times[x.second] = true;
    }
    return true;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    auto x = haystack.find(needle);
    return x == string::npos ? -1 : x;
  }
};
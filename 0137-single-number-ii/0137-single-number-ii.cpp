// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (long long i = 0; i < 32; i++) {
      long long bit = 0;
      for (auto x : nums) {
        bit += (x >> i) & 1;
      }
      bit %= 3;
      ans |= bit << i;
    }
    return ans;
  }
};
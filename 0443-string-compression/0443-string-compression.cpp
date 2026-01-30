
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void modify(vector<char> &chars, int val, int &ind) {
    auto s = to_string(val);
    for (int i = 0; i < s.size(); i++) {
      chars[ind++] = s[i];
    }
  }
  int compress(vector<char> &chars) {
    int curr = 1, i = 0, j = 1, ind = 0;

    while (j < chars.size()) {
      if (chars[j] == chars[i]) {
        curr++;
      } else {
        chars[ind++] = chars[j - 1];
        if (curr > 1)
          modify(chars, curr, ind);
        curr = 1;
        i = j;
      }
      j++;
    }
    chars[ind++] = chars[j - 1];
    if (curr > 1)
      modify(chars, curr, ind);

    return ind;
  }
};
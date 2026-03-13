#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> ans;
    if (nums.size() == 0)
      return ans;

    int i = 0;
    vector<long> tmp;
    while (i <= nums.size()) {
      if (tmp.empty() || (i < nums.size() && nums[i] - tmp.back() == 1))
        tmp.emplace_back(nums[i]);

      else {
        string x = to_string(tmp.front());
        if (tmp.size() > 1)
          x += "->" + to_string(tmp.back());

        ans.emplace_back(x);
        tmp.clear();

        if (i < nums.size())
          tmp.emplace_back(nums[i]);
      }

      i++;
    }
    if (!tmp.empty()) {
      string x = to_string(tmp.front());
      if (tmp.size() > 1)
        x += "->" + to_string(tmp.back());

      ans.emplace_back(x);
    }

    return ans;
  }
};
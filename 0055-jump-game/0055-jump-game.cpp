// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    vector<int> ans(nums.size(), 100007);
    ans[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      for (int j = 1; j <= x && i + j < nums.size(); j++) {
        ans[i + j] = min(ans[i + j], ans[i] + 1);
      }
    }
    return (ans[nums.size() - 1] == 100007)? false :true;
  }
};

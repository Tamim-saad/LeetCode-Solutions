// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int count;
    int prev = 10001;
    int idx = 1;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != prev) {
        count = 0;
        prev = nums[i];
      }
      if (nums[i] == prev)
        count++;
      if (count > 1)
        nums[i] = 10007;
    }

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != 10007)
        nums[idx++] = nums[i];
    }
    return idx;
  }
};
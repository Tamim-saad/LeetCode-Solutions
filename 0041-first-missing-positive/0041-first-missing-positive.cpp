#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int i = 0;

    for (i = 0; i < nums.size(); i++) {
      while (1 <= nums[i] && nums[i] <= nums.size() && nums[i] != i + 1 &&
             nums[i] != nums[nums[i] - 1])
        swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] != i + 1)
        return i + 1;
    return nums.size() + 1;
  }
};
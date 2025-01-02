// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int maxi = -1, i, j, p;
    for (p = nums.size() - 1; p >= 0; p--) {
      if (nums[p] >= maxi)
        maxi = nums[p];
      else {
        i = p + 1;
        j = nums.size() - 1;
        while (i < j) {
          swap(nums[i], nums[j]);
          i++;
          j--;
        }

        i = p;
        while (nums[p] >= nums[i])
          i++;

        swap(nums[p], nums[i]);
        return;
      }
    }

    i = 0;
    j = nums.size() - 1;
    while (i < j) {
      swap(nums[i], nums[j]);
      i++;
      j--;
    }
  }
};
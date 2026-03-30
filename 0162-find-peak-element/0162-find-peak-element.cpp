#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int n = nums.size(), l = 0, h = n - 1;

    while (l < h) {
      int mid = (l + h) / 2;
      long x = mid == 0 ? LONG_MIN : nums[mid - 1];
      long y = nums[mid];
      long z = mid == n ? LONG_MIN : nums[mid + 1];

      if (x < y && y > z)
        return mid;

      if (x < y && y < z)
        l = mid + 1;
      else
        h = mid;
    }
    return l;
  }
};
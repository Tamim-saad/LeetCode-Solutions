// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int maxi = -1, mini = 107, f = 0;
    for (int p = nums.size() - 1; p >= 0; p--) {
      if (nums[p] >= maxi)
        maxi = nums[p];
      else {
        int i = p + 1, j = nums.size() - 1;
        // cout << "i: " << i + 1 << " j: " << j + 1 << endl;
        while (i < j) {
          swap(nums[i], nums[j]);
          i++;
          j--;
        }
        i = p;
        while (nums[p] >= nums[i])
          i++;

        swap(nums[p], nums[i]);
        f = 1;
        break;
      }
    }

    if (!f) {
      int i = 0, j = nums.size() - 1;
      // cout << "i: " << i + 1 << " j: " << j + 1 << endl;
      while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
      }
    }

    // for (auto x : nums)
    //   cout << x << " ";
  }
};
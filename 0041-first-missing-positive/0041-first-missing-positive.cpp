#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

typedef tree<pair<ll, char>, null_type, greater<pair<ll, char>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int mini = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
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
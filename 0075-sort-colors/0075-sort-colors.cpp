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
  void sortColors(vector<int> &nums) {
    int t, p0 = 0, p1 = 0, p2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0)
        p0++;
      if (nums[i] == 1)
        p1++;
      if (nums[i] == 2)
        p2++;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i < p0)
        nums[i] = 0;
      else if (i < p1 + p0)
        nums[i] = 1;
      else // if (p <= i)
        nums[i] = 2;
    }
  }
};
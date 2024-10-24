// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #define ll long long

// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     indexed_multiset;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int count = 0;
    int curr = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (count == 0)
        curr = nums[i];
      if (nums[i] == curr)
        count++;
      else
        count--;
    }
    return curr;
  }
};
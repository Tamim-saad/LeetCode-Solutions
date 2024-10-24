// say Alhamdulillah

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    indexed_multiset st;
    for (int i = 0; i < numbers.size(); i++) {
      int idx =
          upper_bound(numbers.begin(), numbers.end(), target - numbers[i]) -
          numbers.begin() - 1;
      cout << i << " --- " << idx << endl;
      if (idx < numbers.size() && i != idx &&
          numbers[i] + numbers[idx] == target) {
        return {i + 1, idx + 1};
      }
    }
    return {};
  }
};
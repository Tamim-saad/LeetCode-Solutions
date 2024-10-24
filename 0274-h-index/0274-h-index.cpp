// say Alhamdulillah

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    indexed_multiset ms;
    for (int i = 1; i <= citations.size(); i++) {
      ms.insert({citations[i - 1], i});
    }
    for (int i = ms.size(); i > 0; i--) {
      //    auto x = ms[i - 1];
      if (i <= (*ms.find_by_order(i - 1)).first)
        return i;
    }
    return 0;
  }
};
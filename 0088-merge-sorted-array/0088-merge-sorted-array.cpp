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
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = 0;
    int j = 0;
    vector<int> v(m + n);
    int k = 0;

    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        v[k++] = nums1[i++];
      } else {
        v[k++] = nums2[j++];
      }
    }
    while (i < m)
      v[k++] = nums1[i++];
    while (j < n)
      v[k++] = nums2[j++];
    // }
    nums1.resize(v.size());
    for (int i = 0; i < v.size(); i++) {
      // if (i < num1.size())
      nums1[i] = v[i];
      // else
      //   nums1.emplace_back(v[i]);
    }
  }
};
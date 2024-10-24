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
  void merge_sort(int l, int h, vector<int> &v) {
    if (l >= h)
      return;

    int mid = (l + h) / 2;

    merge_sort(l, mid, v);
    merge_sort(mid + 1, h, v);

    int i, j, k;
    vector<ll> sorted(h - l + 1);

    i = l;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= h) {
      if (v[i] < v[j])
        sorted[k++] = v[i++];
      else
        sorted[k++] = v[j++];
    }

    while (i <= mid) {
      sorted[k++] = v[i++];
    }
    while (j <= h) {
      sorted[k++] = v[j++];
    }
    for (int i = l; i <= h; i++) {
      v[i] = sorted[i - l];
    }
  }
  vector<int> sortArray(vector<int> &nums) {
    merge_sort(0, nums.size() - 1, nums);
    return nums;
  }
};

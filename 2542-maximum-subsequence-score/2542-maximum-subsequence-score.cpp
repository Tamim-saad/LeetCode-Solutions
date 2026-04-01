#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<pair<int, int>> v;

    for (int i = 0; i < nums1.size(); i++)
      v.push_back({nums1[i], nums2[i]});

    sort(v.begin(), v.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.second > b.second;
         });

    priority_queue<int, vector<int>, greater<int>> pq;

    long long sum = 0, maxi = 0;
    for (auto x : v) {
      pq.push(x.first);
      sum += x.first;

      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }

      if (pq.size() == k)
        maxi = max(maxi, (long long)sum * (long long)x.second);
    }

    return maxi;
  }
};
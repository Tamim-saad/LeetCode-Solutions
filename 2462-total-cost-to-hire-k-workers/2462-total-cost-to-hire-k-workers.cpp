#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    priority_queue<int, vector<int>, greater<int>> left, right;

    long long ans = 0, n = costs.size(), i = 0, j = n - 1;

    while (i <= j && i < candidates)
      left.push(costs[i++]);
    while (i <= j && right.size() < candidates)
      right.push(costs[j--]);

    while (k--) {
      if (right.empty() || (!left.empty() && left.top() <= right.top())) {
        ans += left.top();
        left.pop();

        if (i <= j)
          left.push(costs[i++]);
      } else {
        ans += right.top();
        right.pop();

        if (i <= j)
          right.push(costs[j--]);
      }
    }

    return ans;
  }
};
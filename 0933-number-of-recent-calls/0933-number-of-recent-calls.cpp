#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
  queue<int> q;
  RecentCounter() {}

  int ping(int t) {
    while (!q.empty() && t - q.front() > 3000) {
      q.pop();
    }
    q.push(t);
    return q.size();
  }
};
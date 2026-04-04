#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int inHand = 0;
    int inHandAfterBuy = INT_MIN;

    for (auto x : prices) {
      inHandAfterBuy = max(inHandAfterBuy, inHand - x);
      inHand = max(inHand, inHandAfterBuy + x - fee);
    }

    return inHand;
  }
};
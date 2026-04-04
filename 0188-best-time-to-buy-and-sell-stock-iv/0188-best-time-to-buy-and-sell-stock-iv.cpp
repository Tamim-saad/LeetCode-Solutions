#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {

    vector<int> inHand(k, 0);
    vector<int> inHandAfterBuy(k, INT_MIN);

    for (auto x : prices) {
      for (int i = 0; i < k; i++) {
        if (i == 0)
          inHandAfterBuy[i] = max(inHandAfterBuy[i], -x);
        else
          inHandAfterBuy[i] = max(inHandAfterBuy[i], inHand[i - 1] - x);

        inHand[i] = max(inHand[i], inHandAfterBuy[i] + x);
      }
    }

    return inHand[k - 1];
  }
};
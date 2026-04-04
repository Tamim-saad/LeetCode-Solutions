#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int inHand = 0;
    int inHandAfterBuy = INT_MIN;
    int inHand2 = 0;
    int inHandAfterBuy2 = INT_MIN;

    for (auto x : prices) {
      inHandAfterBuy = max(inHandAfterBuy, -x);
      inHand = max(inHand, inHandAfterBuy + x);

      inHandAfterBuy2 = max(inHandAfterBuy2, inHand - x);
      inHand2 = max(inHand2, inHandAfterBuy2 + x);
    }

    return inHand2;
  }
};
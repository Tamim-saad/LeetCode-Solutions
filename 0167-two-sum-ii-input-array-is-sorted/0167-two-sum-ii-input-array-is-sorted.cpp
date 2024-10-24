// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
      int idx =
          upper_bound(numbers.begin()+i, numbers.end(), target - numbers[i]) -
          numbers.begin() - 1;
      if (idx < numbers.size() && i != idx &&
          numbers[i] + numbers[idx] == target) {
        return {i + 1, idx + 1};
      }
    }
    return {};
  }
};
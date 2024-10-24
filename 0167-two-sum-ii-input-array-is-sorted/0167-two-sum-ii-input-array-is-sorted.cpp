// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n=numbers.size();
    for (int i = 0; i < n; i++) {
      int idx =
          upper_bound(numbers.begin()+i, numbers.end(), target - numbers[i]) -
          numbers.begin() - 1;
      if (idx < n && i != idx &&
          numbers[i] + numbers[idx] == target) {
        return {i + 1, idx + 1};
      }
    }
    return {};
  }
};
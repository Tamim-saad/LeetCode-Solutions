
class Solution {
public:
  int tribonacci(int n) {
    vector<int> v(38, 0);
    v[1] = 1;
    v[2] = 0;
    for (int i = 1; i <= 37; i++) {
      for (int j = 1; j <= 3; j++) {
        if (i + j < 38)
          v[i + j] += v[i];
      }
    }
    return v[n];
  }
};

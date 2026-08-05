
class Solution {
public:
  long long minEnd(int in, int x) {
    long long i_i = 1, i_m = 1, ans = x;
    in--;

    while (i_i <= in) {
      while (ans & i_m)
        i_m <<= 1;

      if (in & i_i)
        ans |= i_m;

      i_m <<= 1;
      i_i <<= 1;
    }

    return ans;
  }
};
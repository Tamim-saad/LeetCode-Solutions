class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    if (left == right)
      return left;
    if (!left || !right)
      return 0;

    long long f = 1;
    while (f <= left)
      f <<= 1;
    f >>= 1;
    
    if (f <= left && left < (f << 1) && f <= right && right < (f << 1))
      return f | (rangeBitwiseAnd(left - f, right - f));
    return 0;
  }
};
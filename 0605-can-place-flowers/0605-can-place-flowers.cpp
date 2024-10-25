class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int ans = 0, count;

    for (int i = 0; i < flowerbed.size(); i++) {
      if (flowerbed[i] == 0) {
        count = 1;
        if (!i)
          count++;
        while (++i < flowerbed.size() && !flowerbed[i]) {
          count++;
        }
        if (i >= flowerbed.size())
          count++;
        ans += ((count - 1) / 2);
      }
    }
    if (ans >= n)
      return true;
    return false;
  }
};

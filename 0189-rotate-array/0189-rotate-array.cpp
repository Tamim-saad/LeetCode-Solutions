class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    if (k == 0)
      return;
    if (k >= nums.size())
      k %= nums.size();
    reverse(nums.begin(), nums.end());
    int i, j;
    i = 0;
    j = k - 1;
    while (i < j) {
      swap(nums[i++], nums[j--]);
    }
    i = k;
    j = nums.size() - 1;
    while (i < j) {
      {
        swap(nums[i++], nums[j--]);
      }
    }
    for (auto x : nums)
      cout << x << " ";
    cout << endl;
  }
};
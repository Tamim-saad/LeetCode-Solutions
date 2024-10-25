class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
      nums[i] += nums[i - 1];
    }
    int l = 0;
    int r = 0;
    int x;
    for (int i = 0; i < nums.size(); i++) {

      x = (i == 0 ? nums[i] : nums[i] - nums[i - 1]);
      l = (i == 0 ? 0 : nums[i - 1]);
      r = (i == nums.size() - 1 ? 0 : nums[nums.size() - 1] - nums[i]);
      // cout << x << " " << l << " " << r << endl;
      if (l == r)
        return i;
    }
    return -1;
  }
};
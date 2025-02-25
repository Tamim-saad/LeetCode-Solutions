class Solution {
 public:
  vector<int> majorityElement(vector<int> &nums) {
    if (nums.size() == 1) return nums;
    int c1 = 0;
    int c2 = 0;
    int curr1 = 0;
    int curr2 = 1;
    for (auto x : nums) {
      if (x == curr1) {
        c1++;
      } else if (x == curr2) {
        c2++;
      } else if (c1 == 0) {
        curr1 = x;
        c1 = 1;
      } else if (c2 == 0) {
        curr2 = x;
        c2 = 1;
      } else {
        c1--;
        c2--;
      }
    }
    int x1, x2;
    x1 = x2 = 0;

    for (auto x : nums) {
      if (x == curr1)
        x1++;
      else if (x == curr2)
        x2++;
    }
    vector<int> ans;
    if (x1 > (int)(nums.size() / 3)) ans.emplace_back(curr1);
    if (x2 > (int)(nums.size() / 3)) ans.emplace_back(curr2);
    return ans;
  }
};

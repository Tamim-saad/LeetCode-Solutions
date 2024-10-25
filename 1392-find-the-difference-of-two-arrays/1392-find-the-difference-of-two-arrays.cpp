class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());
    vector<vector<int>> v(2);
    for (auto x : s1) {
      if (s2.find(x) == s2.end())
        v[0].emplace_back(x);
    }
    for (auto x : s2) {
      if (s1.find(x) == s1.end())
        v[1].emplace_back(x);
    }
    return v;
  }
};
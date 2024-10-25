class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    vector<int> t = {1};
    ans.push_back(t);
    for (int i = 1; i < numRows; i++) {
      vector<int> v, t = ans[ans.size() - 1];
      v.emplace_back(1);
      for (int j = 0; j < t.size() - 1; j++) {
        v.emplace_back(t[j] + t[j + 1]);
      }
      v.emplace_back(1);
      ans.emplace_back(v);
    }
    return ans;
  }
};

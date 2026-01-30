using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int maxi = *max_element(candies.begin(), candies.end());
    vector<bool> ans;
    for (auto x : candies) {
      if (x + extraCandies >= maxi)
        ans.emplace_back(true);
      else
        ans.emplace_back(false);
    }

    return ans;
  }
};
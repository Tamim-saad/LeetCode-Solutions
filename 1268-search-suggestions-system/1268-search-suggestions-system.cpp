#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    set<string> currList(products.begin(), products.end()), tmpList;
    vector<vector<string>> ans(searchWord.size());
    string px = "";

    for (int i = 0; i < searchWord.size(); i++) {
      px += searchWord[i];
      vector<string> tmp;
      tmpList = {};

      for (auto word : currList) {
        if (word.substr(0, px.size()) == px) {
          tmp.emplace_back(word);
          tmpList.insert(word);
        }
      }
      currList = tmpList;

      sort(tmp.begin(), tmp.end());
      if (tmp.size() <= 3)
        ans[i] = tmp;
      else
        for (int k = 0; k < 3; k++)
          ans[i].emplace_back(tmp[k]);
    }

    return ans;
  }
};
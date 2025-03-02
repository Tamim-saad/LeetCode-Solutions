class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() == 1) {
      return true;
    }
    string ac = "";
    map<char, char> mp;
    for (int i = 0; i < 26; i++) {
      // for(char ch='a'; ch <= 'z'; ch++)
      // {
      char ch = 'a' + i;
      mp[order[i]] = ch;
    }
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words[i].size(); j++) {
        words[i][j] = mp[words[i][j]];
      }
      if (!i) continue;
      if (words[i - 1].compare(words[i]) > 0) {
        // cout << words[i - 1] << " " << words[i] << "\n";
        return false;
      }
    }
    return true;
  }
};
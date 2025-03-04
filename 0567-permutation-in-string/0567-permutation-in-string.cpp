class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    map<char, int> mp;
    for (auto x : s1) mp[x]++;

    int i = 0, j = 0, cnt = s1.length();
    string s = s2;
    while (i < s.length()) {
      if (mp[s[i]]) {
        mp[s[i]]--;
        cnt--;
        i++;
        if (cnt == 0) return true;
      } else {
        mp[s[j]]++;
        j++;
        cnt++;
      }
    }
    return false;
  }
};

class Solution {
public:
  string reverseVowels(string s) {
    vector<int> v;
    char x;
    for (int i = 0; i < s.size(); i++) {
      x = s[i];
      if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
          x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        v.emplace_back(i);
    }
    int i = 0, j = v.size() - 1;
    while (i < j) {
      x = s[v[i]];
      s[v[i]] = s[v[j]];
      s[v[j]] = x;
      i++;
      j--;
    }
    return s;
  }
};
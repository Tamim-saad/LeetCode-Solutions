class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> stq;
    stq.push(-1);
    int maxi = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        stq.push(i);
      } else {
        stq.pop();
        if (stq.empty()) stq.push(i);
        maxi = max(maxi, i - stq.top());
      }
    }
    return maxi;
  }
};
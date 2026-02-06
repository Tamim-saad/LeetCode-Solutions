
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *reverse(ListNode *head) {
    ListNode *next, *prev, *curr;
    next = prev = nullptr;
    curr = head;

    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  int pairSum(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    auto l2 = reverse(slow);
    auto l1 = head;
    int ans = 0;

    while (l2) {
      ans = max(ans, l1->val + l2->val);
      l1 = l1->next;
      l2 = l2->next;
    }

    return ans;
  }
};
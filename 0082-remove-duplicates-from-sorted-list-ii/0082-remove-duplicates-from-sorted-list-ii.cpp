#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    auto prev = dummy;
    auto curr = head;

    while (curr) {
      if (curr->next) {
        if (curr->val != curr->next->val) {
          prev->next = curr;
          prev = prev->next;
          curr = curr->next;
        } else {
          while (curr->next && curr->val == curr->next->val)
            curr = curr->next;

          curr = curr->next;
        }
      } else {
        prev->next = curr;
        prev = prev->next;
        curr = curr->next;
      }
    }

    prev->next = nullptr;
    return dummy->next;
  }
};
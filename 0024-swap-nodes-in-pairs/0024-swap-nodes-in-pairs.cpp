#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *second, *nxt, *prev;
    ListNode dummy(0);
    dummy.next = head;
    prev = &dummy;

    while (head && head->next) {
      nxt = head->next->next;
      second = head->next;

      second->next = head;
      head->next = nxt;

      if (prev) {
        prev->next = second;
      }

      prev = head;
      head = head->next;
    }

    return dummy.next;
  }
};
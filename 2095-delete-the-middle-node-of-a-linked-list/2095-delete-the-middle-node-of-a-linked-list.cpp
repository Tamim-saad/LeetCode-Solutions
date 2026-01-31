#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *deleteMiddle(ListNode *head) {
    if (!head || !head->next)
      return head = nullptr;

    int size = 0;
    auto x = head;
    while (x) {
      size++;
      x = x->next;
    }

    x = head;
    for (int i = 1; i < size / 2; i++)
      x = x->next;

    if (x->next)
      x->next = x->next->next;
    return head;
  }
};
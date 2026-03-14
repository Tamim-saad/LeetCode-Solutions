#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
      return head;

    ListNode *dummy = new ListNode(0);
    auto tmp = dummy;

    auto curr = head;
    int n = 0;
    while (curr) {
      n++;
      curr = curr->next;
    }

    if (k == n)
      return head;
    if (k > n)
      k %= n;

    curr = head;
    for (int i = 1; i < n - k; i++)
      curr = curr->next;

    dummy->next = curr->next;
    curr->next = nullptr;

    while (tmp->next)
      tmp = tmp->next;

    tmp->next = head;
    return dummy->next;
  }
};
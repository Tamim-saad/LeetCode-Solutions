
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *slow, *fast, *tmp;
    slow = fast = head;

    while (fast && fast->next) {
      tmp = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    tmp->next = nullptr;

    auto l = sortList(head);
    auto r = sortList(slow);

    ListNode dummy(0);
    auto ans = &dummy;

    while (l && r) {
      if (l->val <= r->val) {
        ans->next = l;
        ans = ans->next;
        l = l->next;
      } else {
        ans->next = r;
        ans = ans->next;
        r = r->next;
      }
      ans->next = nullptr;
    }
    if (l)
      ans->next = l;

    if (r)
      ans->next = r;

    return dummy.next;
  }
};
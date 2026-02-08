
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
      return nullptr;

    ListNode *slow, *fast;
    slow = fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        break;
    }
    if (slow != fast)
      return nullptr;

    while (head != slow) {
      slow = slow->next;
      head = head->next;
    }
    return head;
  }
};
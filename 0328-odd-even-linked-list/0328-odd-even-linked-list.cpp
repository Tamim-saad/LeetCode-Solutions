#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next || !head->next->next)
      return head;

    ListNode oddHead(0), evenHead(0);
    auto even = &evenHead;
    auto odd = head;

    oddHead.next = odd;
    evenHead.next = odd->next;

    while (odd && odd->next && odd->next->next) {
      even->next = odd->next;
      odd->next = odd->next->next;
      odd = odd->next;
      even = even->next;
    }

    if (odd->next) {
      even->next = odd->next;
    } else
      even->next = nullptr;

    odd->next = evenHead.next;
    return oddHead.next;
  }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode *, bool> mp;
    while (headA) {
      mp[headA] = true;
      headA = headA->next;
    }
    while (headB) {
      if (mp[headB])
        return headB;
      headB = headB->next;
    }
    return nullptr;
  }
};
class Solution {
public:
  tuple<ListNode *, ListNode *, ListNode *> findMiddle(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    if (prev)
      prev->next = nullptr;

    auto startingFirst = (prev == nullptr) ? nullptr : head;
    auto startingSecond = slow->next;
    slow->next = nullptr;

    return {startingFirst, slow, startingSecond};
  }

  TreeNode *sortedListToBST(ListNode *head) {
    if (!head)
      return nullptr;

    auto [leftList, mid, rightlist] = findMiddle(head);
    TreeNode *root = new TreeNode(mid->val);
    root->left = sortedListToBST(leftList);
    root->right = sortedListToBST(rightlist);

    return root;
  }
};
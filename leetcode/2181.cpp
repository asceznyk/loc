class Solution {
public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* curr = head->next;
    ListNode* res = new ListNode(0);
    ListNode* node = res;
    ListNode* prev = nullptr;
    while (curr) {
      if(curr->val == 0) {
        node->next = new ListNode(0);
        prev = node;
        node = node->next;
        curr = curr->next;
        continue;
      }
      node->val += curr->val;
      curr = curr->next;
    }
    prev->next = nullptr;
    return res;
  }
};


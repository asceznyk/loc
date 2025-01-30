class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if(head == nullptr) {
      return head;
    }
    int k = 0;
    ListNode* curr = head;
    while (curr) {
      if (k%2 == 0 && curr->next) {
        int temp = curr->val;
        curr->val = curr->next->val;
        curr->next->val = temp;
      }
      k++;
      curr = curr->next;
    }
    return head;
  }
};



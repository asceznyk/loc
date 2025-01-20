class Solution {
public:
  ListNode* deleteMiddle(ListNode* head) {
    ListNode* curr = head;
    int n = 0;
    while (curr != nullptr) {
      n++;
      curr = curr->next;
    }
    if (n == 1) return nullptr;
    int k = 0;
    curr = head;
    while (k < (n/2)-1) {
      curr = curr->next;
      k++;
    }
    ListNode* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
  }
};





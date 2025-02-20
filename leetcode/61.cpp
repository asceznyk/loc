class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;
    ListNode* curr = head;
    ListNode* prev = head;
    int n = 0;
    while (curr) {
      n++;
      prev = curr;
      curr = curr->next;
    }
    k %= n;
    if (k == 0) return head;
    int i = 0;
    ListNode* jump = head;
    ListNode* pres = head;
    while (jump && i < (n-k-1)) {
      i++;
      jump = jump->next;
    }
    ListNode* res = jump->next; 
    jump->next = nullptr;
    prev->next = pres;
    return res;   
  }
};




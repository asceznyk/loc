class Solution {
public:
  ListNode* reverseLL(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr) {
      ListNode* temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    vector<ListNode*> grp;
    int n = 0;
    ListNode* temp = NULL; 
    while (curr) {
      n++;
      if (n%k == 0) {
        temp = curr->next;
        curr->next = NULL;
        grp.push_back(head);
        head = temp;
        curr = temp;
        continue;
      }
      curr = curr->next;
    }
    ListNode* ref = reverseLL(grp[0]);
    ListNode* res = ref;
    ListNode* tail = NULL;
    for (int i = 1; i < grp.size(); i++) {
      tail = NULL;
      curr = ref;
      while (curr) {
        tail = curr;
        curr = curr->next;
      }
      ref = reverseLL(grp[i]);
      tail->next = ref;
    }
    curr = res;
    tail = NULL;
    while (curr) {
      tail = curr;
      curr = curr->next;
    }
    tail->next = temp;
    return res;
  }
};



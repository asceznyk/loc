class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) return head;
    int i = 1;
    ListNode* curr = head;
    ListNode* prev = nullptr;
    vector<ListNode*> pointers;
    while (curr && i < left) {
      i++;
      prev = curr;
      curr = curr->next;
    }
    ListNode* temp = curr;
    if (temp != head) {
      pointers.push_back(head);
      prev->next = nullptr;
    } 
    pointers.push_back(temp);
    while (curr && i < right) { 
      i++;
      curr = curr->next;
    }
    temp = curr->next;
    curr->next = nullptr;
    pointers.push_back(temp);
    prev = nullptr;
    int start = pointers.size()-2;
    curr = pointers[start];
    while (curr) {
      ListNode* node = curr->next;
      curr->next = prev;
      prev = curr;
      curr = node;
    }
    pointers[start] = prev;
    ListNode* res = pointers[0];
    for (int i = 0; i < pointers.size()-1; i++) {
      ListNode* ptr = pointers[i];
      ListNode* back = nullptr;
      while (ptr) {
        back = ptr;
        ptr = ptr->next;
      }
      back->next = pointers[i+1];
    }
    return res;
  }
};


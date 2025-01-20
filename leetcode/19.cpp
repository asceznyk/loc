class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int l = 0, i = 0;
    ListNode* ptr1 = head;
    while (head != nullptr) {
      l++;
      head = head->next;
    }
    if (n == l) return ptr1->next;
    ListNode* ptr2 = ptr1;
    while (ptr1 != nullptr) {
      if (l-i-1 == n) {
        ListNode* temp = ptr1->next;
        ptr1->next = temp->next;
        delete temp;
        break;
      }
      i++;
      ptr1 = ptr1->next;
    }
    return ptr2;
  }
};


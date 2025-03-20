class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n = 0;
    ListNode* curr = head;
    while (curr) {
      n++;
      curr = curr->next;
    }
    curr = head;
    ListNode* early = curr;
    vector<ListNode*> pointers;
    int x = 0, i = 0, p = 0; 
    if (n%k == 0) {
      x = n/k;
      while (curr) {
        i++;
        if (i%x != 0) {
          curr = curr->next;
          continue;
        }
        pointers.push_back(early);
        early = curr->next;
        curr->next = nullptr;
        curr = early;
      }
    } else {
      x = (n/k)+1; i = 0;
      bool isset = false;
      while (curr) {
        i++;
        if (i%x != 0) {
          curr = curr->next;
          continue;
        }
        pointers.push_back(early);
        early = curr->next;
        curr->next = nullptr;
        curr = early;
        if (p < (n%k)) p++;
        if (p == (n%k) && !isset) {
          x = x-1;
          i = 0;
          isset = true;
        }
      }   
    }
    while (pointers.size() < k) {
      if (early) {
        pointers.push_back(early);
        early = nullptr;
        continue;
      }
      pointers.push_back(nullptr);
    }
    return pointers;
  }
};


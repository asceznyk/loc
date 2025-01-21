class Solution {
public:
  ListNode* sortList(ListNode* head) {
    vector<int> snums;
    ListNode* curr = head;
    while (curr != nullptr) {
      snums.push_back(curr->val);
      curr = curr->next;
    }
    int n = snums.size();
    if (n == 0) return nullptr;
    sort(snums.begin(), snums.end());
    ListNode* node = new ListNode(snums[0]);
    ListNode* origin = node;
    for (int i = 1; i < n; i++) {
      node->next = new ListNode(snums[i]);
      node = node->next; 
    }
    return origin;
  }
};


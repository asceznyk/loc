class Solution {
public:
  void reorderList(ListNode* head) {
    ListNode* curr = head;
    vector<int> arr;
    while (curr != nullptr) {
      arr.push_back(curr->val);
      curr = curr->next;
    }
    int n = arr.size();
    if (n == 1) return;
    int l = 1, r = n-1;
    curr = head;
    bool isLeft = false;
    while (l <= r) {
      curr = curr->next;
      if (isLeft) {
        curr->val = arr[l];
        l++;
        isLeft = false;
      } else {
        curr->val = arr[r];
        r--;
        isLeft = true;
      }
    }
  }
};


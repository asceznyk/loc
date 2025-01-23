class Solution {
public:
  ListNode* buildLL(vector<int>& arr) {
    int n = arr.size();
    if(n == 0) return nullptr;
    ListNode* node = new ListNode(arr[0]);
    ListNode* head = node;
    for (int i = 1; i < n; i++) {
      node->next = new ListNode(arr[i]);
      node = node->next; 
    }
    return head;
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    vector<int> bigVec;
    for(int i = 0; i < k; i++) {
      ListNode* curr = lists[i];
      while (curr) {
        bigVec.push_back(curr->val);
        curr = curr->next;
      }
    }
    sort(bigVec.begin(), bigVec.end());
    ListNode* head = buildLL(bigVec);
    return head;
  }
};


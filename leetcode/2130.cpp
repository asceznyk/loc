//Time - O(n), Space - O(n) 
class Solution {
public:
  int pairSum(ListNode* head) {
    vector<int> nums;
    ListNode* curr = head;
    while (curr != nullptr) {
      nums.push_back(curr->val);
      curr = curr->next;
    }
    int n = nums.size(), ans = 0;
    for(int i = 0; i < n/2; i++) {
      ans = max(nums[i] + nums[n-i-1], ans);
    }
    return ans;
  }
};

//Time O(n), Space - O(1)
class Solution {
public:
  int pairSum(ListNode* head) {
    ListNode* curr = head;
    ListNode* fast = head;
    ListNode* newL = NULL;
    while (fast) {
      fast = fast->next->next;
      ListNode* temp = curr->next;
      curr->next = newL;
      newL = curr;
      curr = temp;
    }
    int ans = 0;
    while (curr) {
      ans = max(ans, (curr->val+newL->val));
      curr = curr->next;
      newL = newL->next;
    }
    return ans;
  }
};



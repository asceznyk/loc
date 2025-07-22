class Solution {
public:
  vector<int> llToArr(ListNode* curr) {
    vector<int> arr;
    while (curr) {
      arr.push_back(curr->val);
      curr = curr->next;
    }
    return arr;
  }
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> arr1 = llToArr(l1);
    vector<int> arr2 = llToArr(l2);
    int s1 = arr1.size(), s2 = arr2.size();
    int n = 0;
    if (s1 > s2) {
      arr2.insert(arr2.begin(), (s1-s2), 0);
      n = s1;
    }
    else if (s2 > s1) {
      arr1.insert(arr1.begin(), (s2-s1), 0);
      n = s2;
    } else  n = s1;
    vector<int> res(n,0);
    int carry = 0;
    for (int i = n-1; i > -1; i--) {
      int x = carry + arr1[i] + arr2[i];
      if (x < 10) {
        res[i] = x;
        carry = 0;
        continue;
      }
      if (i == 0) {
        res[i] = x-10;
        res.insert(res.begin(), 1, 1);
        continue;
      }
      res[i] = x-10;
      carry = (x >= 10 ? 1 : 0); 
    }
    ListNode* node = new ListNode(res[0]);
    ListNode* head = node;
    for (int i = 1; i < res.size(); i++) {
      node->next = new ListNode(res[i]);
      node = node->next; 
    }
    return head;
  }
};


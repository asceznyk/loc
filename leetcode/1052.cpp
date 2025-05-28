class Solution {
public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
    int n = customers.size();
    int satisfied = 0;
    vector<int> crappy(n); 
    for (int i = 0; i < n; i++) {
      if(grumpy[i] == 0) {
        satisfied += customers[i];
        continue;
      }
      crappy[i] = customers[i];
    }
    for (int i = 0; i < k; i++) satisfied += crappy[i];
    int ans = satisfied;
    for (int i = k; i < n; i++) {
      satisfied += crappy[i] - crappy[i-k];
      if (satisfied > ans) {
        ans = satisfied;
        maxRange[0] = i-k;
        maxRange[1] = i;
      }
    }
    return ans;
  }
};



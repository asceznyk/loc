class Solution {
public:
  const int MOD = 1e9+7;
  int kInversePairs(int n, int k) {
    vector<int> prev(k+1, 0);
    prev[0] = 1;
    for (int i = 1; i < n+1; i++) {
      vector<int> curr(k+1, 0);
      int total = 0;
      for (int j = 0; j < k+1; j++) {
        total = (total + prev[j]) % MOD;
        if (j >= i) total = (total - prev[j-i] + MOD) % MOD;
        curr[j] = total;
      }
      prev = curr;
    }
    return prev[k];      
  }
};


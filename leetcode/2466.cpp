class Solution {
public:
  int MOD = 1e9+7;
  int dfs(int k, int low, int high, int zero, int one, vector<int>& dp) {
    if (k > high) return 0;
    if (k == high) return 1;
    if (dp[k] != -1) return dp[k];
    return dp[k] = ((k >= low ? 1: 0) + \
                 dfs(k+zero, low, high, zero, one, dp) + \
                 dfs(k+one, low, high, zero, one, dp)) % MOD;
  }
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high+2, -1);
    return dfs(0, low, high, zero, one, dp) % MOD;
  }
};


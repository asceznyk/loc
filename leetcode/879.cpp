class Solution {
public:
  int m = 0;
  const int MOD = 1e9+7;
  int dfs(
    int i, int n, int p, int minProfit,
    vector<int>& group, vector<int>& profit,
    vector<vector<vector<int>>>& dp
  ) {
    if (n < 0) return 0;
    if (i == m) return (p > 0 ? 0 : 1);
    if (dp[i][n][max(0,p)] != -1) return dp[i][n][max(0,p)];
    long long take = 1LL*dfs(i+1, n-group[i], p-profit[i], \
        minProfit, group, profit, dp);
    long long skip = 1LL*dfs(i+1, n, p, minProfit, group, profit, dp);
    return dp[i][n][max(0,p)] = (take + skip) % MOD;
  }
  int profitableSchemes(
    int n, int minProfit,
    vector<int>& group, vector<int>& profit
  ) {
    m = group.size();
    vector<vector<vector<int>>> dp(m+1,
      vector<vector<int>>(n+1, vector<int>(minProfit+1, -1))
    );
    return dfs(0, n, minProfit, minProfit, group, profit, dp);
  }
};




class Solution {
public:
  int dfs(
    int i, int k,
    vector<vector<int>>& prefix,
    vector<vector<int>>& dp
  ) {
    if (i < 0) return 0;
    if (dp[i][k] != 0) return dp[i][k];
    int res = dfs(i-1, k, prefix, dp);
    int h = min((int)prefix[i].size(), k);
    for (int j = 0; j < h; j++)
      res = max(res, prefix[i][j] + dfs(i-1, k-j-1, prefix, dp));
    dp[i][k] = res;
    return dp[i][k];
  }
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    vector<vector<int>> prefix;
    for (int i = 0; i < n; i++) {
      int m = piles[i].size();
      vector<int> ipref(m);
      int p = 0;
      for (int j = 0; j < m; j++) {
        p += piles[i][j];
        ipref[j] = p;
      }
      prefix.push_back(ipref);
    }
    return dfs(n-1, k, prefix, dp);
  }
};



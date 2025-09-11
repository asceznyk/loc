class Solution {
public:
  int m = 0;
  const int INF = 1e9+7;
  int dfs(int i, int j, vector<int>& newCuts, vector<vector<int>>& dp) {
    if (j - i == 1) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int res = INF;
    for (int k = i+1; k <= j-1; k++) {
      res = min(
        res,
        (newCuts[j]-newCuts[i]) + \
        dfs(i, k, newCuts, dp) + dfs(k, j, newCuts, dp) 
      );
    }
    return dp[i][j] = res;
  }
  int minCost(int n, vector<int>& cuts) {
    m = cuts.size();
    sort(cuts.begin(), cuts.end());
    vector<int> newCuts(m+2);
    newCuts[m+1] = n;
    for (int i = 0; i < m; i++) newCuts[i+1] = cuts[i];
    vector<vector<int>> dp(m+2, vector<int>(m+2, -1));
    return dfs(0, m+1, newCuts, dp);
  }
};


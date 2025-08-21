class Solution {
public:
  int INF = 1e7;
  int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    int n = matrix.size();
    if (i == n) return 0;
    if (dp[i][j] != INF) return dp[i][j];
    int res = INF;
    for (int k = 0; k < n; k++) {
      if (k == j) continue;
      res = min(res, matrix[i][j] + dfs(i+1, k, matrix, dp));
    }
    return dp[i][j] = res; 
  }
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 1) return matrix[0][0];
    int ans = INF;
    vector<vector<int>> dp(n+1, vector<int>(n+1, INF));
    for (int j = 0; j < n; j++) ans = min(ans, dfs(0, j, matrix, dp));
    return ans;
  }
};


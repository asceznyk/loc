class Solution {
public:
  int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    int n = matrix.size();
    if (i == n) return 0;
    if (j < 0 || j > n-1) return INT_MAX;
    if (dp[i][j] != INT_MAX) return dp[i][j];
    return dp[i][j] = matrix[i][j] + min(
      min(dfs(i+1, j+1, matrix, dp), dfs(i+1, j-1, matrix, dp)),
      dfs(i+1, j, matrix, dp)
    );
  }
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int ans = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int j = 0; j < n; j++) ans = min(ans, dfs(0, j, matrix, dp));
    return ans;
  }
};


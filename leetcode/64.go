func minPathSum(grid [][]int) int {
  var m, n int = len(grid), len(grid[0]) 
  dp := make([][]int, m)
  for i := range dp { dp[i] = make([]int, n) }
  dp[0][0] = grid[0][0];
  for i := 1; i < m; i++ { dp[i][0] = grid[i][0] + dp[i-1][0] }
  for j := 1; j < n; j++ { dp[0][j] = grid[0][j] + dp[0][j-1] }
  for i := 1; i < m; i++ {
    for j := 1; j < n; j++ {
      dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j])
    }
  }
  return dp[m-1][n-1]
}




func minInsertions(s string) int {
  n := len(s)
  dp := make([][]int, n)
  for i := 0; i < n; i++ {
    dp[i] = make([]int, n)
  }
  for i := n-1; i > -1; i-- {
    dp[i][i] = 1
    for j := i+1; j < n; j++ {
      if s[i] == s[j] {
        dp[i][j] = 2 + dp[i+1][j-1]
        continue
      }
      dp[i][j] = max(dp[i+1][j], dp[i][j-1])
    }
  }
  fmt.Println("ans", n-dp[0][n-1])
  return n-dp[0][n-1]
}

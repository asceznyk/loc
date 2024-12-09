func numDistinct(s string, t string) int {
  n, m := len(s), len(t)
  if(m > n) {
    return 0
  }
  dp := make([][]int, n+1)
  for i := 0; i < n+1; i++ {
    dp[i] = make([]int, m+1)
  }
  for i := 0; i < n+1; i++ {
    dp[i][m] = 1
  }
  for i := n-1; i > -1; i-- {
    for j := m-1; j > -1; j-- {
      if(s[i] == t[j]) {
        dp[i][j] += dp[i+1][j+1]
      }
      dp[i][j] += dp[i+1][j]
    }
  }
  return dp[0][0]
}


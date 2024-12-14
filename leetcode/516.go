func dfs(s string, i int, j int, dp [][]int) int {
  if i > j { 
    return 0
  }
  if dp[i][j] != 0 {
    return dp[i][j]
  }
  if s[i] == s[j] {
    x := 2
    if (i == j) {
      x = 1
    }
    dp[i][j] = x+dfs(s, i+1, j-1, dp)
    return dp[i][j]
  }
  dp[i][j] = max(dfs(s, i, j-1, dp), dfs(s, i+1, j, dp))
  return dp[i][j]
}

// DP with memoization
func longestPalindromeSubseq(s string) int {
  n := len(s)
  dp := make([][]int, n)
  for i := 0; i < n; i++ {
    dp[i] = make([]int, n)
  }
  return dfs(s, 0, n-1, dp)
}

// Iterative DP
func longestPalindromeSubseq(s string) int {
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
  return dp[0][n-1]
}

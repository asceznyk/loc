func dfs(n int, dp []int) int {
  if n <= 0 { return 0 }
  if dp[n] != 0 { return dp[n] }
  x := 1
  m := 10001
  for int(x*x) <= n {
    m = min(m, 1+dfs(n-x*x, dp))
    x++
  }
  dp[n] = m
  return dp[n]
}

func numSquares(n int) int {
  dp := make([]int, n+1)
  return dfs(n, dp)
}


func maxProfit(k int, prices []int) int {
  n := len(prices)
  dp := make([][][]int, n+1)
  for i := 0; i < n+1; i++ {
    dp[i] = make([][]int, k+1)
    for j := 0; j < k+1; j++ {
      dp[i][j] = make([]int, 2)
    }
  }
  for i := n-1; i > -1; i-- {
    for j := 1; j < k+1; j++ {
      for b := 0; b < 2; b++ {
        leave := dp[i+1][j][b]
        if b == 0 {
          dp[i][j][b] = max(dp[i+1][j][1]-prices[i], leave)
        } else {
          dp[i][j][b] = max(dp[i+1][j-1][0]+prices[i], leave)
        }
      }
    }
  }
  return dp[0][k][0]
}



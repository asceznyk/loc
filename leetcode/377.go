func combinationSum4(nums []int, target int) int {
  dp := make([]int, target+1)
  dp[0] = 1
  for i := 1; i < target+1; i++ {
    for _, c := range nums {
      if(i-c < 0) { continue }
      dp[i] += dp[i-c]
    }
  }
  return 0
}


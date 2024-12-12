func dfs(satisfaction []int, i int, t int, dp map[string]int) int {
  if i >= len(satisfaction) {
    return 0
  }
  key := strconv.Itoa(i) + "_" + strconv.Itoa(t)
  v, exists := dp[key]
  if exists {
    return v
  }
  dp[key] = max(
    (satisfaction[i]*t)+dfs(satisfaction, i+1, t+1, dp), 
    dfs(satisfaction, i+1, t, dp),
  )
  return dp[key]
}

func maxSatisfaction(satisfaction []int) int {
  sort.Ints(satisfaction)
  dp := make(map[string]int)
  return dfs(satisfaction, 0, 1, dp)
}

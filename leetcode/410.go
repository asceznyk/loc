func dfs(nums []int, prefix []int, i int, k int, dp map[string]int) int {
  n := len(nums)
  if k == 1 {
    return prefix[n]-prefix[i]
  }
  key := strconv.Itoa(i)+"_"+strconv.Itoa(k)
  v, exists := dp[key]
  if exists {
    return v
  }
  currSum, res := 0, 1000000007 
  for j := i; j < n-k+1 && currSum <= res; j++ {
    currSum += nums[j]
    maxSum := max(currSum, dfs(nums, prefix, j+1, k-1, dp))
    res = min(res, maxSum)
  }
  dp[key] = res
  return res
}

func splitArray(nums []int, k int) int {
  n := len(nums)
  prefix := make([]int, n+1)
  prefix[0] = 0
  for i := 1; i < n+1; i++ {
    prefix[i] = prefix[i-1] + nums[i-1]
  }
  dp := make(map[string]int)
  return dfs(nums, prefix, 0, k, dp)
}


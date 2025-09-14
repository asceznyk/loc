func checkSubarraySum(nums []int, k int) bool {
  n := len(nums)
  p := 0
  if n == 1 {
    return false
  }
  prefixSum := make([]int, n)
  for i := 0; i < n-1; i++ {
    if nums[i] == 0 && nums[i+1] == 0 {
      return true
    }
    p += nums[i]
    prefixSum[i] = p
  }
  prefixSum[n-1] = p + nums[n-1]
  modIdx := make(map[int]int)
  for i, v := range prefixSum {
    m := v % k
    j, exists := modIdx[m]
    if (exists && i-j > 1) || (m == 0 && i > 0) {
      return true
    }
    if (exists) {
      continue 
    }
    modIdx[m] = i
  }
  return false
}


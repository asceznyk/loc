func getSumAbsoluteDifferences(nums []int) []int {
  n := len(nums)
  prefix := make([]int, n+1)
  prefix[0] = 0
  for i := 1; i < n+1; i++ {
    prefix[i] = prefix[i-1] + nums[i-1]
  }
  res := make([]int, n)
  for t := 0; t < n; t++ {
    res[t] = ((t*nums[t]) - prefix[t]) + ((prefix[n]-prefix[t]) - (n-t)*nums[t])
  }
  return res
}

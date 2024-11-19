func rotate(nums []int, k int)  {
  n := len(nums)
  if k == n {
    return
  }
  k %= n
  cc := append(nums[n-k:], nums[:n-k]...)
  for i, v := range cc {
    nums[i] = v
  }
}

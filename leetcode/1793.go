func maximumScore(nums []int, k int) int {
  n, l, r, m := len(nums), k, k, nums[k]
  score := 0
  for l > -1 && r < n {
    if nums[l] >= nums[r] {
      m = min(m, nums[l])
      score = max(score, m*(r-l))
      l--
    } else {
      m = min(m, nums[r])
      score = max(score, m*(r-l))
      r++
    }
  }
  for l > -1 {
    m = min(m, nums[l])
    score = max(score, m*(r-l))
    l--
  }
  for r < n {
    m = min(m, nums[r])
    score = max(score, m*(r-l))
    r++
  }
  return score
}

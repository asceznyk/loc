func singleNonDuplicate(nums []int) int {
  n := len(nums)
  l, r := 0, n-1
  for l <= r {
    m := int((l+r)/2)
    x, p, q, s := nums[m], -1, -1, 0
    if m > 0 { p = nums[m-1] }
    if m < n-1 { q = nums[m+1] }
    if x != p && x != q {
      return x
    } else if x == p {
      s = m-1
    } else {
      s = m
    }
    if s % 2 == 1 {
      r = m-1
    } else { 
      l = m+1 
    }
  }
  return -1
}


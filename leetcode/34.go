func binarySearchLeft(nums []int, n int, target int) int {
  l, r := 0, n
  for l < r {
    m := int((l+r)/2)
    if nums[m] < target {
      l = m+1
    } else {
      r = m
    }
  }
  if(l < n && nums[l] == target) { return l }
  return -1
}

func binarySearchRight(nums []int, n int, target int) int {
  l, r := 0, n
  for l < r {
    m := int((l+r)/2)
    if nums[m] > target {
      r = m
    } else {
      l = m+1
    }
  }
  if(r > 0 && nums[r-1] == target) {
    return r-1
  }
  return -1
}

func searchRange(nums []int, target int) []int {
  n := len(nums)
  if(n <= 0) { return []int{-1,-1} }
  return []int{binarySearchLeft(nums, n, target), binarySearchRight(nums, n, target)}
}


func firstMissingPositive(nums []int) int {
  pMap := make(map[int]bool)
  for i := 0; i < len(nums); i++ {
    x := nums[i]
    if(x <= 0 || x > len(nums)) {
      continue
    }
    pMap[x] = true
  }
  k := 1
  for true {
    _, exists := pMap[k]
    if !exists {
      break
    }
    k++
  }
  return k
}


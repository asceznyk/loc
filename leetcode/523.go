package main

import "fmt"

func checkSubarraySum(nums []int, k int) bool {
  n := len(nums)
  p := 0
  if n == 1 {
    fmt.Println("FALSE")
    return false
  }
  prefixSum := make([]int, n)
  for i := 0; i < n-1; i++ {
    if nums[i] == 0 && nums[i+1] == 0 {
      fmt.Println("TRUE")
      return true
    }
    p += nums[i]
    prefixSum[i] = p
  }
  prefixSum[n-1] = p + nums[n-1]
  fmt.Println(prefixSum)
  modIdx := make(map[int]int)
  for i, v := range prefixSum {
    m := v % k
    j, exists := modIdx[m]
    if (exists && i-j > 1) || (m == 0 && i > 0) {
      fmt.Println("TRUE")
      return true
    }
    if (exists) {
      continue 
    }
    modIdx[m] = i
  }
  fmt.Println("FALSE")
  return false
}

func main() {
  checkSubarraySum([]int{23,2,4,6,7}, 6)
  checkSubarraySum([]int{23,2,6,4,7}, 6)
  checkSubarraySum([]int{23,2,6,4,7}, 13)
  checkSubarraySum([]int{23,2,4,6,6}, 7)
  checkSubarraySum([]int{0}, 1)
  checkSubarraySum([]int{0,1,0,3,0,4,0,4,0}, 5)
  checkSubarraySum([]int{5,2,4}, 5)
  checkSubarraySum([]int{2,4,3}, 6)
  checkSubarraySum([]int{1,3,0,6}, 6)
  checkSubarraySum([]int{1,2,12}, 6)
  checkSubarraySum([]int{30000,1,2,3}, 3)
}


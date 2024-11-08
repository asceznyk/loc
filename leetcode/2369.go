func validSubarray(arr []int) bool {
  m := len(arr)
  if m != 2 && m != 3 {
    return false
  }
  if m == 2 && (arr[0] ^ arr[1] == 0) {
    return true
  }
  if m == 3 && ((arr[0] ^ arr[1] == 0 && arr[1] ^ arr[2] == 0) ||
  (arr[2] - arr[1] == 1 && arr[1] - arr[0] == 1)) {
    return true
  } 
  return false
}

func validPartition(nums []int) bool {
  n := len(nums) 
  dp := make([]bool, n)
  for i := 0; i < n; i++ {
    if(i < 3) {
      dp[i] = validSubarray(nums[:i+1])
      continue
    }
    for j := 1; j <= 2; j++ {
      dp[i] = dp[i] || (dp[i-j-1] && validSubarray(nums[i-j:i+1])) 
    } 
  }
  return dp[n-1]
}


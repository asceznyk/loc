func absInt(x int) int {
  if x < 0 {
    return -x
  }
  return x
} 

func findClosestElements(arr []int, k int, x int) []int {
  n := len(arr)
  if x <= arr[0] {
    return arr[:k]
  }
  if k >= n {
    return arr
  }
  prefix := make([]int, n)
  p := 0 
  for i := 0; i < n; i++ {
    p += absInt(x - arr[i])
    prefix[i] = p
  }
  j, q, m := 0, 0, 100000000
  for i := 0; i <= n-k; i++ {
    s := prefix[i+k-1] - q
    if s < m {
      m = s
      j = i
    }
    q = prefix[i]
  }
  return arr[j:j+k]
}


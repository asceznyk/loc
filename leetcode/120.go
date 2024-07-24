func minimumTotal(triangle [][]int) int {
  n := len(triangle)
  curr := make([]int, n+1)
  next := make([]int, n+1)
  for i := n-1; i > -1; i-- {
    for j := 0; j < len(triangle[i]); j++ {
      curr[j] = triangle[i][j] + min(next[j], next[j+1])
    }
    next = curr
  }
  return curr[0]
}



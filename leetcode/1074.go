func numSubmatrixSumTarget(matrix [][]int, target int) int {
  n, m := len(matrix[0]), len(matrix)
  ans := 0
  prefix := make([][]int, m)
  for i := range prefix {
    prefix[i] = make([]int, n)
    for j := 0; j < n; j++ {
      prefix[i][j] = matrix[i][j]
    }
    for j := 1; j < n; j++ {
      prefix[i][j] += prefix[i][j-1]
    }
  }
  for l := 0; l < n; l++ {
    for r := l; r < n; r++ {
      lookup := make(map[int]int)
      lookup[0] = 1
      csum := 0
      for i := 0; i < m; i++ {
        q := 0
        if l > 0 {
          q = prefix[i][l-1]
        } 
        csum += prefix[i][r] - q
        c, exists := lookup[csum-target]
        if exists {
          ans += c
        }
        lookup[csum]++
      }
    }
  }
  return ans
}



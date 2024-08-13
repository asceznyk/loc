func makePrefix(grid [][]int, n int) [][]int64 {
  prefix := make([][]int64, 2)
  for i := 0; i < 2; i++ {
    p := int64(0)
    prefix[i] = make([]int64, n)
    for j := n-1; j > -1; j-- {
      p += int64(grid[i][j])
      prefix[i][j] = p
    }
  }
  return prefix
}

func gridGame(grid [][]int) int64 {
  n := len(grid[0])
  prefix := makePrefix(grid, n)
  i, j := 0, 0
  a, b := int64(0), int64(0)
  grid[i][j] = 0
  for i < 1 && j < n-1 {
    a, b = prefix[i][j+1], int64(grid[i+1][j])+(prefix[i+1][0] - prefix[i+1][j])
    y, x := 0, 0
    if a > b {
      y, x = i, j+1
      j++
    } else {
      y, x = i+1, j
      i++
    }
    grid[y][x] = 0
  }
  for j < n {
    grid[i][j] = 0
    j++
  }
  for i < 2 {
    grid[i][j-1] = 0
    i++
  }
  prefix2 := makePrefix(grid, n)
  return max(prefix2[0][0], prefix2[1][0])
}

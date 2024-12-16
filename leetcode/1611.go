func powInt(x int, y int) int {
  return int(math.Pow(float64(x), float64(y)))
}

func minimumOneBitOperations(n int) int {
  if n == 0 {
    return 0
  }
  x, k := 1, 0
  for x <= n {
    x <<= 1
    k++
  }
  x >>= 1
  return powInt(2, k) - 1 - minimumOneBitOperations(n^x)
}


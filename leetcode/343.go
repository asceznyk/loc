func integerBreak(n int) int {
  if n <= 3 {
    return n-1
  }
  if n == 4 {
    return n
  }
  m := 1
  for i := 5; i < n+1; i++ {
    if (i-2) % 3 == 0 {
      m *= 3
    } 
  }
  return (2 + ((n-2)%3)) * m
}



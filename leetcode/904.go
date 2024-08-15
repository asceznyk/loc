func totalFruit(fruits []int) int {
  n := len(fruits)
  if n == 1 { return 1 }
  numCnt := make(map[int]int)
  l, r := 0, 1
  numCnt[fruits[l]]++
  ans := r-l
  for l <= r && r < n {
    first := fruits[l]
    last := fruits[r]
    if(len(numCnt) > 2) {
      numCnt[first]--
      if(numCnt[first] == 0) { delete(numCnt, first) }
      l++
      continue
    }
    numCnt[last]++
    r++
    if(len(numCnt) > 2)  { continue }
    ans = max(r-l, ans)
  }
  return ans
}

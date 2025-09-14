func mergeAlternately(word1 string, word2 string) string {
  n, m := len(word1), len(word2)
  p1, p2, x := 0, 0, 0
  ans := ""
  for x < min(n, m) {
    ans += string(word1[p1]) + string(word2[p2])
    p1++
    p2++
    x++ 
  }
  if x >= n {
    ans += string(word2[x:m])
  } else {
    ans += string(word1[x:n])
  }
  return ans
}


func countPalindromicSubsequence(s string) int {
  sChars := make(map[rune]int)
  for i, r := range s { sChars[r] = i }
  count := 0
  for k, last := range sChars {
    curr := 0
    uniq := make(map[rune]int)
    first := strings.IndexRune(s, k)
    for i := first+1; i < last; i++ {
      r := rune(s[i])
      if _, e := uniq[r]; e { continue }
      curr++
      uniq[r] = 1
    }
    count += curr
  }
  return count 
}



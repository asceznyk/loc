func minWindow(s string, t string) string {
  m := len(s)
  n := len(t)
  if n > m {
    return ""
  }
  sMap := make(map[rune]int)
  tMap := make(map[rune]int)
  for _, c := range t {
    tMap[rune(c)]++
  }
  i, j := 0, 0
  expand := true
  candidates := make(map[int]int)
  for i <= j {
    if expand {
      if j >= m {
        break
      }
      sMap[rune(s[j])]++
      j++
    } else {
      sMap[rune(s[i])]--
      i++
    }
    l := 0
    expand = true
    for k, v := range tMap {
      w, e := sMap[k]
      if !e {
        continue
      }
      if w >= v {
        l++
      }
    }
    if l == len(tMap) {
      expand = false
      candidates[j] = i
    }
  }
  ans := ""
  minLen := 100000 
  for j, i := range candidates {
    if j-i < minLen {
      minLen = j-i
      ans = s[i:j]
    }
  }
  return ans
}



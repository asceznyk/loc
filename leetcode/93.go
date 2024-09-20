var sList = []string{}

func backtrack(s string, i int, addr string, d int) {
  if d >= 4 {
    if i == len(s) {
      sList = append(sList, addr)
    } 
    return
  }
  for j := 1; j <= 3; j++ {
    if i+j > len(s) {
      break
    }
    r := s[i:i+j]
    if r[0] == '0' && len(r) > 1 {
      break
    }
    x, _ := strconv.Atoi(r)
    if x < 0 || x > 255 {
      break
    }
    sAddr := addr + r
    if d < 3 {
      sAddr += "."
    }
    backtrack(s, i+j, sAddr, d+1)
  }
}

func restoreIpAddresses(s string) []string {
  n := len(s)
  if n > 12 || n < 4 {
    return []string{}
  }
  sList = []string{}
  backtrack(s, 0, "", 0)
  return sList
}

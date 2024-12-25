func lcs(str1 string, str2 string, i int, j int, mem [][]string) string {
  if i >= len(str1) || j >= len(str2) {
    return ""
  }
  if mem[i][j] != "" {
    return mem[i][j]
  }
  if str1[i] == str2[j] {
    mem[i][j] = (string(str1[i])+lcs(str1, str2, i+1, j+1, mem))
    return mem[i][j]
  }
  s1 := lcs(str1, str2, i, j+1, mem)
  s2 := lcs(str1, str2, i+1, j, mem)
  mem[i][j] = s2
  if len(s1) > len(s2) {
    mem[i][j] = s1
  } 
  return mem[i][j]
}

func shortestCommonSupersequence(str1 string, str2 string) string {
  n, m := len(str1), len(str2)
  mem := make([][]string, n)
  for i := 0; i < n; i++ {
    mem[i] = make([]string, m)
  }
  com := lcs(str1, str2, 0, 0, mem)
  l := len(com)
  if l == 0 {
    return str1+str2
  }
  i, j, k := 0, 0, 0
  ans := ""
  for k < l {
    if str1[i] == com[k] && str2[j] == com[k] {
      ans += string(com[k])
      i++
      j++
      k++
    } else if str1[i] == com[k] {
      ans += string(str2[j])
      j++
    } else {
      ans += string(str1[i])
      i++
    }
  }
  for i < n {
    ans += string(str1[i])
    i++
  }
  for j < m {
    ans += string(str2[j])
    j++
  }
  return ans
}



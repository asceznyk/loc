package main

import (
  "fmt"
)

func findAnagrams(s string, p string) []int {
  idxs := []int{}
  k, n := len(p), len(s)
  if(k > n) { return idxs } 
  pMap := make([]int, 26)
  sMap := make([]int, 26)
  for _, c := range p { pMap[c-97]++ }
  for i := 0; i < k-1; i++ { sMap[s[i]-97]++ }
  for i := k-1; i < n; i++  {
    sMap[s[i]-97]++
    if(i-k >= 0) { sMap[s[i-k]-97]-- } 
    isAnagram := true;
    for j := 0; j < 26; j++ {
      if (pMap[j] != sMap[j]) { isAnagram = false } 
    }
    if(isAnagram) { idxs = append(idxs, i-k+1) } 
  }
  fmt.Println(idxs)
  return idxs
}

func main() {
  findAnagrams("cbaebabacd", "abc")
  findAnagrams("abab", "ab")
  findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa")
}



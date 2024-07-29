func minStickers(stickers []string, target string) int {
  n := len(target)
  dp := make([]int, (1 << n))
  for i := 0; i < len(dp); i++ { dp[i] = -1 }
  dp[0] = 0
  for mask := 0; mask < len(dp); mask++ {
    if dp[mask] == -1 {
      continue
    }
    for _, word := range stickers {
      maskApplied := mask
      for _, c := range word {
        for i := 0; i < n; i++ {
          if (maskApplied>>i)&1 == 1 { continue }
          if rune(target[i]) == c {
            maskApplied |= (1 << (n-i-1))
            break
          }
        }
      }
      if dp[maskApplied] == -1 || dp[maskApplied] > dp[mask] + 1 {
        dp[maskApplied] = dp[mask] + 1
      }
    }
  }
  return dp[(1<<n)-1]
}
